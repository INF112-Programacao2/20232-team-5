#include "controller_usuario.h"
#include <vector>
#include "perfil.h"

ControllerUsuario::ControllerUsuario(Session *session) : _session(session) {}

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
  return RetornoController::Completo;
}