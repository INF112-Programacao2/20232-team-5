#include "main_initializer.h"
#include "config.h"

MainInitializer::MainInitializer()
{
}

MainInitializer::~MainInitializer()
{
  destroyMenus();
  destroyControllers();
  destroyData();
  delete _session;
  delete _database;
}

bool MainInitializer::initialize()
{
  _database = new Database(conninfo);
  if (!_database->initializeConn())
    return false;
  _session = new Session();
  initializeData();
  initializeControllers();
  initializeMenus();
  return true;
}

void MainInitializer::initializeData()
{
  _dataModalidade = new DataModalidade(_database);
  _dataAutenticacao = new DataAutenticacao(_database);
  _dataUsuario = new DataUsuario(_database);
  _dataCadastroPendente = new DataCadastroPendente(_database);
  _dataTurma = new DataTurma(_database);
  _dataGraduacao = new DataGraduacao(_database);
}

void MainInitializer::initializeControllers()
{
  _controllerAutenticacao = new ControllerAutenticacao(_session, _dataModalidade, _dataAutenticacao, _menuCliente, _menuProfessor, _menuAdministrador);
  _controllerCadastroPendente = new ControllerCadastroPendente(_session, _dataCadastroPendente, _dataUsuario, _dataModalidade);
  _controllerUsuario = new ControllerUsuario(_session, _dataUsuario);
  _controllerTurma = new ControllerTurma(_session, _dataTurma);
  _controllerGraduacao = new ControllerGraduacao(_session, _dataGraduacao);
}

void MainInitializer::initializeMenus()
{
  _menuOpcoesGraduacao = new MenuOpcoesGraduacao("Graduação", _controllerGraduacao);
  _menuOpcoesUsuario = new MenuOpcoesUsuario("Opções do Usuário", _controllerUsuario);
  _menuOpcoesTurma = new MenuOpcoesTurma("Turmas", _controllerTurma);
  _menuCadastros = new MenuCadastros("Cadastros", _session, _menuOpcoesGraduacao, _menuOpcoesTurma);
  _menuCliente = new MenuCliente("Menu Inicial - Cliente", _session, _menuOpcoesUsuario);
  _menuProfessor = new MenuProfessor("Menu Inicial - Professor", _session, _menuOpcoesUsuario);
  _menuAdministrador = new MenuAdministrador("Menu Inicial - Administrador", _session, _menuOpcoesUsuario, _menuCadastroPendente, _menuCadastros);
  _menuInicial = new MenuInicial("Paiva Team", _controllerAutenticacao);
}

void MainInitializer::destroyData()
{
  delete _dataGraduacao;
  delete _dataTurma;
  delete _dataCadastroPendente;
  delete _dataModalidade;
  delete _dataUsuario;
  delete _dataAutenticacao;
}

void MainInitializer::destroyControllers()
{
  delete _controllerGraduacao;
  delete _controllerTurma;
  delete _controllerCadastroPendente;
  delete _controllerUsuario;
  delete _controllerAutenticacao;
}

void MainInitializer::destroyMenus()
{
  delete _menuOpcoesGraduacao;
  delete _menuOpcoesTurma;
  delete _menuCadastros;
  delete _menuCadastroPendente;
  delete _menuOpcoesUsuario;
  delete _menuAdministrador;
  delete _menuProfessor;
  delete _menuCliente;
  delete _menuInicial;
}

void MainInitializer::executar()
{
  _menuInicial->executar();
}