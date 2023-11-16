#include "main_initializer.h"

MainInitializer::MainInitializer()
{
  _controllerLogin = new ControllerLogin();
  _menuInicial = new MenuInicial("Menu Inicial", _controllerLogin);
}

MainInitializer::~MainInitializer()
{
  delete _menuInicial;
  delete _controllerLogin;
}

void MainInitializer::executar()
{
  _menuInicial->executar();
}