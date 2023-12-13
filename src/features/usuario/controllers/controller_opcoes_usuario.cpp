#include "controller_opcoes_usuario.h"
#include <vector>
#include "enums.h"
#include <exception>
#include "modalidade.h"
#include "cad_pendente.h"

ControllerOpcoesUsuario::ControllerOpcoesUsuario(Session *session, DataUsuario *dataUsuario, DataModalidade *dataModalidade, DataAutenticacao *dataAutenticacao, DataPerfil *dataPerfil) : _session(session), _dataUsuario(dataUsuario), _dataModalidade(dataModalidade), _dataAutenticacao(dataAutenticacao), _dataPerfil(dataPerfil) {}

std::string ControllerOpcoesUsuario::getTipoStr(TipoPerfil tipo)
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

int ControllerOpcoesUsuario::escolhaPerfil()
{
  std::cout << "Em qual perfil você deseja entrar?" << std::endl;
  std::vector<TipoPerfil> perfilList = _session->getUsuario()->getPerfilList();
  int perfil;
  for (int i = 0; i < perfilList.size(); i++)
  {
    std::cout << i + 1 << " - " << getTipoStr(perfilList[i]);
    if (i == _session->getCurrentPerfil())
      std::cout << " [ATUAL]";
    std::cout << std::endl;
  }
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

RetornoController ControllerOpcoesUsuario::alternaPerfil()
{
  if (_session->getUsuario()->getPerfilList().size() == 1)
  {
    std::cout << "Você possui apenas 1 perfil!" << std::endl;
    return RetornoController::Completo;
  }
  int currentPerfil = escolhaPerfil();
  _session->setCurrentPerfil(currentPerfil);
  finalizarTela();
  return RetornoController::AlternaPerfil;
}

RetornoController ControllerOpcoesUsuario::trocaSenha()
{
  return handleExecution(
      [&]
      {
        std::string oldPas, newPas;
        std::cout << "Informe a senha antiga: ";
        std::cin >> oldPas;
        // Se senha estiver incorreta, interrompe
        if (_session->getUsuario()->getSenha() != oldPas)
        {
          std::cout << "Senha incorreta!" << std::endl;
          return RetornoController::Completo;
        }
        std::cout << "Informe a nova senha: ";
        std::cin >> newPas;
        std::cout << "Confirme a nova senha: ";
        // Lê apenas para confirmar a senha (não precisa salvar o valor)
        readVal<std::string>(
            [&](std::string senha)
            {
              if (senha != newPas)
              {
                std::cout << "As senhas não batem!" << std::endl;
                return false;
              }
              return true;
            });

        // Salva senha no banco
        _dataUsuario->salvarSenha(_session->getUsuario()->getChaveUsu(), newPas);
        // Atualiza senha na instância de usuário em Session
        _session->getUsuario()->setSenha(newPas);
        std::cout << "Senha alterada com sucesso!" << std::endl;
      });
}

RetornoController ControllerOpcoesUsuario::verDados()
{
  return handleExecution(
      [&]
      {
        Usuario *usuario = _session->getSelectedUsuario();
        bool temPerfilCliente = _dataPerfil->checaTemPerfil(usuario->getChaveUsu(), TipoPerfil::Cliente);
        std::cout
            << "DADOS DO USUÁRIO" << std::endl;
        std::cout << "CHAVE: " << usuario->getChaveUsu() << std::endl;
        std::cout << "NOME: " << usuario->getNome() << std::endl;
        std::cout << "APELIDO: " << usuario->getApelido() << std::endl;
        std::cout << "DATA DE NASC.: " << usuario->getDtNascimento() << std::endl;
        std::cout << "CPF: " << usuario->getCpf() << std::endl;
        std::cout << "SEXO: " << (usuario->getSexo() == 'M' ? "Masculino" : "Feminino") << std::endl;
        std::cout << "LOGIN: " << usuario->getLogin() << std::endl;
        hold();
      });
}

RetornoController ControllerOpcoesUsuario::novoCadastro()
{
  CadPendente *cad = nullptr;
  char tipo;
  handleExecution(
      [&]
      {
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
              modalidadeList = _dataModalidade->buscaListaModalidadesDisponiveis(_session->getSelectedUsuario()->getChaveUsu());
          if (!modalidadeList.size())
          {
            std::cout << "Não há mais modalidades disponíveis!" << std::endl;
            return;
          }
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
          cad = new CadPendente(nullnum, _session->getSelectedUsuario()->getChaveUsu(), tipo, chaveMod);
        }
        else
        {
          if (_dataPerfil->checaTemPerfil(_session->getSelectedUsuario()->getChaveUsu(), static_cast<TipoPerfil>(tipo)))
          {
            std::cout << "Você já possui esse perfil cadastrado!" << std::endl;
            return;
          }
          // Cria professor
          cad = new CadPendente(nullnum, _session->getSelectedUsuario()->getChaveUsu(), tipo);
        }
        _dataAutenticacao->inscreveCadastroPendente(cad);
        std::cout << "Cadastro submetido para aprovação do administrador!" << std::endl;
      });
  if (cad)
    delete cad;
  return RetornoController::Completo;
}