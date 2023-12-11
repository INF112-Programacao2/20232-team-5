#include "main_initializer.h"
#include "config.h"

MainInitializer::MainInitializer()
{
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
  destroyCadastroPendente();
  destroyAluno();
  destroyModalidade();
  destroyUsuario();
  destroyPerfil();
  destroyData();
  delete _session;
}

bool MainInitializer::initialize()
{
  _database = new Database(conninfo);
  if (!_database->initializeConn())
    return false;
  _session = new Session();
  initializeData();
  initializePerfil();
  initializeUsuario();
  initializeModalidade();
  initializeAluno();
  initializeCadastroPendente();
  initializeTurma();
  initializeGraduacao();
  _menuCadastros = new MenuCadastros("Cadastros", _session, _menuOpcoesGraduacao, _menuOpcoesTurma, _menuOpcoesModalidade, _menuUsuario);
  _menuCliente = new MenuCliente("Menu Inicial - Cliente", _session, _menuOpcoesUsuario);
  _menuProfessor = new MenuProfessor("Menu Inicial - Professor", _session, _menuOpcoesUsuario);
  _menuAdministrador = new MenuAdministrador("Menu Inicial - Administrador", _session, _menuOpcoesUsuario, _menuCadastroPendente, _menuCadastros);
  initializeAutenticacao();
  _menuInicial = new MenuInicial("Paiva Team", _controllerAutenticacao);
  return true;
}

void MainInitializer::initializeData()
{
  _dataAutenticacao = new DataAutenticacao(_database);
  _dataUsuario = new DataUsuario(_database);
  _dataCadastroPendente = new DataCadastroPendente(_database);
  _dataModalidade = new DataModalidade(_database);
  _dataTurma = new DataTurma(_database);
  _dataGraduacao = new DataGraduacao(_database);
  _dataAluno = new DataAluno(_database);
  _dataPerfil = new DataPerfil(_database);
  _dataPagamento = new DataPagamento(_database);
}

void MainInitializer::initializeAutenticacao()
{
  _controllerAutenticacao = new ControllerAutenticacao(_session, _dataModalidade, _dataAutenticacao, _menuCliente, _menuProfessor, _menuAdministrador, _dataPerfil);
}

void MainInitializer::initializeUsuario()
{
  _controllerEditarUsuario = new ControllerEditarUsuario(_session, _dataUsuario);
  _menuEditarUsuario = new MenuEditarUsuario("Editar Dados", _controllerEditarUsuario);
  _controllerOpcoesUsuario = new ControllerOpcoesUsuario(_session, _dataUsuario, _dataModalidade, _dataAutenticacao, _dataPerfil, _dataPagamento);
  _controllerUsuario = new ControllerUsuario(_session, _dataUsuario, _controllerOpcoesUsuario, _menuEditarUsuario, _menuPerfil);
  _menuOpcoesUsuario = new MenuOpcoesUsuario("Opções do Usuário", _session, _controllerOpcoesUsuario, _menuEditarUsuario);
  _menuUsuario = new MenuUsuario("Usuários", _controllerUsuario);
}

void MainInitializer::initializeCadastroPendente()
{
  _controllerCadastroPendente = new ControllerCadastroPendente(_session, _dataCadastroPendente, _dataUsuario, _dataModalidade, _dataAutenticacao, _dataGraduacao, _dataAluno, _dataPerfil, _dataPagamento);
  _menuCadastroPendente = new MenuCadastroPendente("Cadastros Pendentes", _controllerCadastroPendente);
}

void MainInitializer::initializeModalidade()
{
  _controllerModalidade = new ControllerModalidade(_session, _dataModalidade);
  _menuOpcoesModalidade = new MenuOpcoesModalidade("Modalidades", _controllerModalidade);
}

void MainInitializer::initializeTurma()
{
  _controllerTurma = new ControllerTurma(_session, _dataTurma);
  _menuOpcoesTurma = new MenuOpcoesTurma("Turmas", _controllerTurma);
}

void MainInitializer::initializeGraduacao()
{
  _controllerGraduacao = new ControllerGraduacao(_session, _dataGraduacao);
  _menuOpcoesGraduacao = new MenuOpcoesGraduacao("Graduação", _controllerGraduacao);
}

void MainInitializer::initializeAluno()
{
}

void MainInitializer::initializePerfil()
{
  _controllerPerfil = new ControllerPerfil(_session, _dataPerfil);
  _menuPerfil = new MenuPerfil("Perfis do Usuário", _controllerPerfil);
}

void MainInitializer::destroyData()
{
  delete _dataAutenticacao;
  delete _dataUsuario;
  delete _dataCadastroPendente;
  delete _dataModalidade;
  delete _dataTurma;
  delete _dataGraduacao;
  delete _dataAluno;
  delete _dataPerfil;
  delete _dataPagamento;
}

void MainInitializer::destroyAutenticacao()
{
  delete _controllerAutenticacao;
}

void MainInitializer::destroyUsuario()
{
  delete _menuUsuario;
  delete _menuOpcoesUsuario;
  delete _menuEditarUsuario;
  delete _controllerUsuario;
  delete _controllerOpcoesUsuario;
  delete _controllerEditarUsuario;
}

void MainInitializer::destroyCadastroPendente()
{
  delete _menuCadastroPendente;
  delete _controllerCadastroPendente;
}

void MainInitializer::destroyModalidade()
{
  delete _menuOpcoesModalidade;
  delete _controllerModalidade;
}

void MainInitializer::destroyTurma()
{
  delete _menuOpcoesTurma;
  delete _controllerTurma;
}

void MainInitializer::destroyGraduacao()
{
  delete _menuOpcoesGraduacao;
  delete _controllerGraduacao;
}

void MainInitializer::destroyAluno()
{
}

void MainInitializer::destroyPerfil()
{
  delete _menuPerfil;
  delete _controllerPerfil;
}

void MainInitializer::executar()
{
  // _session->setUsuario(_dataUsuario->buscaUsuarioByChave(1));
  // _session->setCurrentPerfil(0);
  // _menuUsuario->executar();
  _menuInicial->executar();
}