#include "main_initializer.h"

MainInitializer::MainInitializer()
{
  _session = new Session();
  initializeModalidade();
  _menuCliente = new MenuCliente("Menu Inicial - Cliente", _session);
  _menuProfessor = new MenuProfessor("Menu Inicial - Professor", _session);
  _menuAdministrador = new MenuAdministrador("Menu Inicial - Administrador", _session);
  initializeAutenticacao();
  _menuInicial = new MenuInicial("Paiva Team", _controllerAutenticacao);
}

MainInitializer::~MainInitializer()
{
  delete _menuInicial;
  destroyAutenticacao();
  delete _menuAdministrador;
  delete _menuProfessor;
  delete _menuCliente;
  destroyModalidade();
  delete _session;
}

void MainInitializer::initializeAutenticacao()
{
  _dataAutenticacao = new DataAutenticacao();
  _controllerAutenticacao = new ControllerAutenticacao(_session, _dataModalidade, _dataAutenticacao, _menuCliente, _menuProfessor, _menuAdministrador);
}

void MainInitializer::initializeModalidade()
{
  _dataModalidade = new DataModalidade();
}

void MainInitializer::destroyAutenticacao()
{
  delete _controllerAutenticacao;
  delete _dataAutenticacao;
}

void MainInitializer::destroyModalidade()
{
  delete _dataModalidade;
}

void MainInitializer::executar()
{
  _menuInicial->executar();
}