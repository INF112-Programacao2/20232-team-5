#include "controller_usuario.h"
#include <vector>
#include "perfil.h"
#include <exception>

ControllerUsuario::ControllerUsuario(Session *session, DataUsuario *dataUsuario) : _session(session), _dataUsuario(dataUsuario) {}

int ControllerUsuario::escolhaPerfil()
{
  std::cout << "Em qual perfil você deseja entrar?" << std::endl;
  std::vector<Perfil> perfilList = _session->getUsuario()->getPerfilList();
  int perfil;
  for (int i = 0; i < perfilList.size(); i++)
  {
    std::cout << i + 1 << " - ";
    if (perfilList[i].getTipo() == 'C')
      std::cout << "Cliente";
    else if (perfilList[i].getTipo() == 'P')
      std::cout << "Professor";
    else
      std::cout << "Administrador";
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

RetornoController ControllerUsuario::alternaPerfil()
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

RetornoController ControllerUsuario::trocaSenha()
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

  try
  {
    // Salva senha no banco
    _dataUsuario->salvarSenha(_session->getUsuario()->getChaveUsu(), newPas);
    // Atualiza senha na instância de usuário em Session
    _session->getUsuario()->setSenha(newPas);
    std::cout << "Senha alterada com sucesso!" << std::endl;
  }
  catch (std::exception e)
  {
    std::cout << "Ocorreu um erro inesperado!" << std::endl;
    std::cerr << e.what() << std::endl;
  }

  return RetornoController::Completo;
}