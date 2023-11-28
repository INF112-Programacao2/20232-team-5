#include "main_initializer.h"

MainInitializer::MainInitializer()
{
  _session = new Session();
  initializeUsuario();
  initializeModalidade();
  _menuCliente = new MenuCliente("Menu Inicial - Cliente", _session, _menuOpcoesUsuario);
  _menuProfessor = new MenuProfessor("Menu Inicial - Professor", _session, _menuOpcoesUsuario);
  _menuAdministrador = new MenuAdministrador("Menu Inicial - Administrador", _session, _menuOpcoesUsuario);
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
  destroyUsuario();
  delete _session;
}

void MainInitializer::initializeAutenticacao()
{
  _dataAutenticacao = new DataAutenticacao();
  _controllerAutenticacao = new ControllerAutenticacao(_session, _dataModalidade, _dataAutenticacao, _menuCliente, _menuProfessor, _menuAdministrador);
}

void MainInitializer::initializeUsuario()
{
  _dataUsuario = new DataUsuario();
  _controllerUsuario = new ControllerUsuario(_session, _dataUsuario);
  _menuOpcoesUsuario = new MenuOpcoesUsuario("Opções do Usuário", _controllerUsuario);
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

void MainInitializer::destroyUsuario()
{
  delete _menuOpcoesUsuario;
  delete _controllerUsuario;
}

void MainInitializer::executar()
{
  _menuInicial->executar();
}