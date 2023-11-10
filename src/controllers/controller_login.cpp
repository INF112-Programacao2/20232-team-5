#include "controller_login.h"

RetornoController ControllerLogin::executar()
{
  std::cout << "Tela de login\n";
  finalizarTela();
  return RetornoController::Completo;
}