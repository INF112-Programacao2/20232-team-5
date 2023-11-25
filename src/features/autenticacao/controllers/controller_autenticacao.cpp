#include <iostream>
#include "controller_autenticacao.h"
#include <vector>
#include "modalidade.h"
#include "cad_pendente.h"
#include "exception"

// Classe responsável por controlar as operações de autenticação

ControllerAutenticacao::ControllerAutenticacao(Session *session, DataModalidade *dataModalidade, DataAutenticacao *dataAutenticacao, MenuCliente *menuCliente, MenuProfessor *menuProfessor, MenuAdministrador *menuAdministrador) : _session(session), _dataModalidade(dataModalidade), _dataAutenticacao(dataAutenticacao), _menuCliente(menuCliente), _menuProfessor(menuProfessor), _menuAdministrador(menuAdministrador) {}

RetornoController ControllerAutenticacao::realizaCadastro()
{
  std::string apelido;
  std::string dtNascimento;
  std::string cpf;
  std::string rg;
  char sexo;
  std::string nome;
  std::string login;
  std::string senha;
  char tipo;
  CadPendente *cad;

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

  std::cout << "Digite o RG: ";
  rg = readLine();

  std::cout << "Digite o sexo (M/F): ";
  sexo = readVal<char>(
      [&](char sexo)
      {
        if (sexo != 'M' && sexo != 'F')
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });

  std::cout << "Digite o login: ";
  login = readLine();

  std::cout << "Digite a senha: ";
  senha = readLine();

  std::cout << "Deseja solicitar cadastro como cliente (C) ou professor (P)? ";
  tipo = readVal<char>(
      [&](char tipo)
      {
        if (tipo != 'C' && tipo != 'P')
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });

  if (tipo == 'C')
  {
    finalizarTela();
    int opcaoMod, chaveMod;
    std::vector<Modalidade>
        modalidadeList = _dataModalidade->leListaModalidade();
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

  try
  {
    _dataAutenticacao->inscreveCadastroPendente(cad);
    std::cout << "Cadastro submetido para aprovação do administrador!" << std::endl;
  }
  catch (std::exception e)
  {
    std::cout << "Ocorreu um erro inesperado!" << std::endl;
    std::cout << e.what() << std::endl;
  }

  delete cad;
  return RetornoController::Completo;
}

RetornoController ControllerAutenticacao::realizaLogin()
{
  try
  {
    std::string login;
    std::string senha;

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
    std::cout << "Usuário autenticado!" << std::endl;
    // Busca lista de perfis do usuário
    std::vector<Perfil> perfilList = _dataAutenticacao->buscaPerfis(usuario->getChaveUsu());
    usuario->setPerfilList(perfilList);
    int currentPerfil = 0;
    // Se possui mais de um perfil, pergunta em qual quer entrar
    if (perfilList.size() > 1)
    {
      finalizarTela();
      std::cout << "Em qual perfil você deseja entrar?" << std::endl;
      for (int i = 0; i < perfilList.size(); i++)
      {
        std::cout << i + 1 << " - ";
        if (perfilList[i].getTipo() == 'C')
          std::cout << "Cliente" << std::endl;
        else if (perfilList[i].getTipo() == 'P')
          std::cout << "Professor" << std::endl;
        else
          std::cout << "Administrador" << std::endl;
      }
      std::cout << "Sua escolha: ";
      currentPerfil = readVal<int>(
          [&](int option)
          {
            if (option < 1 || option > perfilList.size())
            {
              std::cout << "Opção inválida!" << std::endl;
              return false;
            }
            return true;
          });
      currentPerfil--;
    }
    // Salva usuário e perfil na sessão
    _session->setUsuario(usuario);
    _session->setCurrentPerfil(currentPerfil);

    // Redireciona para o menu apropriado
    finalizarTela();
    if (perfilList[currentPerfil].getTipo() == 'C')
      return _menuCliente->executar();
    else if (perfilList[currentPerfil].getTipo() == 'P')
      return _menuProfessor->executar();
    else
      return _menuAdministrador->executar();
  }
  catch (std::exception e)
  {
    std::cout << "Ocorreu um erro inesperado!" << std::endl;
    std::cout << e.what() << std::endl;
    return RetornoController::Completo;
  }
}