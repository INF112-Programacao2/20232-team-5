#include "main_initializer.h"

MainInitializer::MainInitializer()
{
  _session = new Session();
  _controllerAutenticacao = new ControllerAutenticacao(_session);
  _menuInicial = new MenuInicial("Menu Inicial", _controllerAutenticacao);
}

MainInitializer::~MainInitializer()
{
  delete _menuInicial;
  delete _controllerAutenticacao;
  delete _session;
}

void MainInitializer::executar()
{
  _menuInicial->executar();
}