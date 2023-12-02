#include "main_initializer.h"
#include "database.h"

MainInitializer::MainInitializer()
{
  _session = new Session();
  initializeUsuario();
  initializeCadastroPendente();
  initializeModalidade();
  initializeTurma();
  initializeGraduacao();
  _menuCadastros = new MenuCadastros("Cadastros", _session, _menuOpcoesGraduacao, _menuOpcoesTurma);
  _menuCliente = new MenuCliente("Menu Inicial - Cliente", _session, _menuOpcoesUsuario);
  _menuProfessor = new MenuProfessor("Menu Inicial - Professor", _session, _menuOpcoesUsuario);
  _menuAdministrador = new MenuAdministrador("Menu Inicial - Administrador", _session, _menuOpcoesUsuario, _menuCadastroPendente, _menuCadastros);
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
  delete _menuCadastros;
  destroyGraduacao();
  destroyTurma();
  destroyModalidade();
  destroyCadastroPendente();
  destroyUsuario();
  delete _session;
  destroyConn();
}

bool MainInitializer::initializeConn()
{
  _conn = PQconnectdb(conninfo.c_str());
  if (PQstatus(_conn) != CONNECTION_OK)
  {
    // Printa o erro
    printf("Erro conectando com o banco de dados: %s\n", PQerrorMessage(_conn));
    destroyConn();
    return false;
  }
  return true;
}

void MainInitializer::initializeAutenticacao()
{
  _dataAutenticacao = new DataAutenticacao(_conn);
  _controllerAutenticacao = new ControllerAutenticacao(_session, _dataModalidade, _dataAutenticacao, _menuCliente, _menuProfessor, _menuAdministrador);
}

void MainInitializer::initializeUsuario()
{
  _dataUsuario = new DataUsuario(_conn);
  _controllerUsuario = new ControllerUsuario(_session, _dataUsuario);
  _menuOpcoesUsuario = new MenuOpcoesUsuario("Opções do Usuário", _controllerUsuario);
}

void MainInitializer::initializeCadastroPendente()
{
  _dataCadastroPendente = new DataCadastroPendente(_conn);
  _controllerCadastroPendente = new ControllerCadastroPendente(_session, _dataCadastroPendente, _dataUsuario, _dataModalidade);
  _menuCadastroPendente = new MenuCadastroPendente("Cadastros Pendentes", _controllerCadastroPendente);
}

void MainInitializer::initializeModalidade()
{
  _dataModalidade = new DataModalidade(_conn);
}

void MainInitializer::initializeTurma()
{
  _dataTurma = new DataTurma(_conn);
  _controllerTurma = new ControllerTurma(_session, _dataTurma);
  _menuOpcoesTurma = new MenuOpcoesTurma("Turmas", _controllerTurma);
}

void MainInitializer::initializeGraduacao()
{
  _dataGraduacao = new DataGraduacao(_conn);
  _controllerGraduacao = new ControllerGraduacao(_session, _dataGraduacao);
  _menuOpcoesGraduacao = new MenuOpcoesGraduacao("Graduação", _controllerGraduacao);
}

void MainInitializer::destroyConn()
{
  // Finaliza a conexão
  PQfinish(_conn);
}

void MainInitializer::destroyAutenticacao()
{
  delete _controllerAutenticacao;
  delete _dataAutenticacao;
}

void MainInitializer::destroyUsuario()
{
  delete _menuOpcoesUsuario;
  delete _controllerUsuario;
  delete _dataUsuario;
}

void MainInitializer::destroyCadastroPendente()
{
  delete _menuCadastroPendente;
  delete _controllerCadastroPendente;
  delete _dataCadastroPendente;
}

void MainInitializer::destroyModalidade()
{
  delete _dataModalidade;
}

void MainInitializer::destroyTurma()
{
  delete _menuOpcoesTurma;
  delete _controllerTurma;
  delete _dataTurma;
}

void MainInitializer::destroyGraduacao()
{
  delete _menuOpcoesGraduacao;
  delete _controllerGraduacao;
  delete _dataGraduacao;
}

void MainInitializer::executar()
{
  _menuInicial->executar();
}