#include <iostream>
#include "controller_autenticacao.h"
#include "modalidade.h"
#include "cad_pendente.h"
#include "exception"
#include "database_error.h"
#include "enums.h"

// Classe responsável por controlar as operações de autenticação

ControllerAutenticacao::ControllerAutenticacao(Session *session, DataModalidade *dataModalidade, DataAutenticacao *dataAutenticacao, MenuCliente *menuCliente, MenuProfessor *menuProfessor, MenuAdministrador *menuAdministrador, DataPerfil *dataPerfil) : _session(session), _dataModalidade(dataModalidade), _dataAutenticacao(dataAutenticacao), _dataPerfil(dataPerfil), _menuCliente(menuCliente), _menuProfessor(menuProfessor), _menuAdministrador(menuAdministrador) {}

std::string ControllerAutenticacao::getTipoStr(TipoPerfil tipo)
{
  switch (tipo)
  {
  case TipoPerfil::Cliente:
    return "Cliente";
  case TipoPerfil::Professor:
    return "Professor";
  default:
    return "Administrador";
  }
}

bool ControllerAutenticacao::checaExisteLogin(std::string login)
{
  if (_dataAutenticacao->existeLogin(login))
  {
    std::cout << "Login já existente!" << std::endl;
    return false;
  }
  return true;
}

RetornoController ControllerAutenticacao::realizaCadastro()
{
  std::string apelido;
  std::string dtNascimento;
  std::string cpf;
  std::string rg = nullstr;
  char sexo;
  std::string nome;
  std::string login;
  std::string senha;
  char tipo;
  CadPendente *cad;

  handleExecution(
      [&]
      {
        // Solicitar valores ao usuário
        std::cout << "CADASTRO" << std::endl;

        std::cout << "Digite o nome: ";
        nome = readLine();

        std::cout << "Digite o apelido: ";
        apelido = readLine();

        std::cout << "Digite a data de nascimento: ";
        dtNascimento = readLine();

        std::cout << "Digite o CPF: ";
        cpf = readLine();

        std::cout << "Digite o sexo (M/F): ";
        sexo = std::toupper(readVal<char>(
            [&](char sexo)
            {
              if (std::tolower(sexo) != 'm' && std::tolower(sexo) != 'f')
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            }));

        std::cout << "Digite o login: ";
        login = readVal<std::string>(
            [&](std::string val)
            { return checaExisteLogin(val); });

        std::cout << "Digite a senha: ";
        senha = readLine();

        std::cout << "Deseja solicitar cadastro como cliente (C) ou professor (P)?" << std::endl;
        std::cout << "Sua escolha: ";
        tipo = readVal<char>(
            [&](char val)
            {
              val = std::toupper(val);
              if (val != TipoPerfil::Cliente && val != TipoPerfil::Professor)
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            });
        tipo = std::toupper(tipo);
        if (tipo == TipoPerfil::Cliente)
        {
          finalizarTela();
          int opcaoMod, chaveMod;
          std::vector<Modalidade>
              modalidadeList = _dataModalidade->buscaListaModalidade();
          std::cout << "Seleção de modalidade: " << std::endl;
          for (int i = 0; i < modalidadeList.size(); i++)
            std::cout << i + 1 << " - " << modalidadeList[i].getNome() << std::endl;
          std::cout << "Sua escolha: ";
          opcaoMod = readVal<int>(
              [&](int opcao)
              {
                if (opcao < 1 || opcao > modalidadeList.size())
                {
                  std::cout << "Opção inválida!" << std::endl;
                  return false;
                }
                return true;
              });
          chaveMod = modalidadeList[opcaoMod - 1].getChaveMod();
          // Cria aluno
          cad = new CadPendente(0, nome, apelido, dtNascimento, cpf, rg, sexo, login, senha, tipo, chaveMod);
        }
        else
        {
          // Cria professor
          cad = new CadPendente(0, nome, apelido, dtNascimento, cpf, rg, sexo, login, senha, tipo);
        }
        _dataAutenticacao->inscreveCadastroPendente(cad);
        std::cout << "Cadastro submetido para aprovação do administrador!" << std::endl;
      });

  if (cad)
    delete cad;
  return RetornoController::Completo;
}

int ControllerAutenticacao::escolhaPerfil()
{
  std::cout << "Em qual perfil você deseja entrar?" << std::endl;
  std::vector<TipoPerfil> perfilList = _session->getUsuario()->getPerfilList();
  int perfil;
  for (int i = 0; i < perfilList.size(); i++)
    std::cout << i + 1 << " - " << getTipoStr(perfilList[i]) << std::endl;
  std::cout << "Sua escolha: ";
  perfil = readVal<int>(
      [&](int option)
      {
        if (option < 1 || option > perfilList.size())
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });
  perfil--;
  return perfil;
}

RetornoController ControllerAutenticacao::realizaLogin()
{
  RetornoController retorno;
  std::string login;
  std::string senha;
  handleExecution(
      [&]
      {
        std::cout << "Digite o login: ";
        login = readLine();

        std::cout << "Digite a senha: ";
        senha = readLine();

        // Procura por usuário com esse login
        Usuario *usuario = _dataAutenticacao->buscaUsuario(login);
        if (!usuario)
        {
          std::cout << "Usuário não encontrado!" << std::endl;
          return RetornoController::Completo;
        }
        // Verifica se senhas batem
        if (usuario->getSenha() != senha)
        {
          std::cout << "Senha incorreta!" << std::endl;
          return RetornoController::Completo;
        }

        std::cout << "Bem-vindo, " << usuario->getNome() << "!" << std::endl;

        // Busca lista de perfis do usuário
        std::vector<TipoPerfil> perfilList = _dataPerfil->buscaPerfis(usuario->getChaveUsu());
        usuario->setPerfilList(perfilList);
        // Salva usuário na sessão
        _session->setUsuario(usuario);

        int currentPerfil = 0;
        // Se possui mais de um perfil, pergunta em qual quer entrar
        if (perfilList.size() > 1)
        {
          finalizarTela();
          currentPerfil = escolhaPerfil();
        }
        // Salva perfil na sessão
        _session->setCurrentPerfil(currentPerfil);

        // Redireciona para o menu apropriado
        finalizarTela();
        do
        {
          if (perfilList[_session->getCurrentPerfil()] == TipoPerfil::Cliente)
            retorno = _menuCliente->executar();
          else if (perfilList[_session->getCurrentPerfil()] == TipoPerfil::Professor)
            retorno = _menuProfessor->executar();
          else
            retorno = _menuAdministrador->executar();
        } while (retorno == RetornoController::AlternaPerfil);
      });
  if (retorno == RetornoController::Sair)
    return retorno;
  return RetornoController::Completo;
}