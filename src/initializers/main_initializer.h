#ifndef INF112_MAIN_INITIALIZER_H
#define INF112_MAIN_INITIALIZER_H
#include <database.h>
#include <string>
#include "session.h"
#include "menu_inicial.h"
#include "menu_cliente.h"
#include "menu_professor.h"
#include "menu_administrador.h"
#include "menu_cadastro_pendente.h"
#include "menu_cadastros.h"
#include "menu_opcoes_turma.h"
#include "menu_opcoes_graduacao.h"
#include "menu_opcoes_modalidade.h"
#include "menu_editar_usuario.h"
#include "controller_autenticacao.h"
#include "controller_opcoes_usuario.h"
#include "controller_cadastro_pendente.h"
#include "controller_turma.h"
#include "controller_graduacao.h"
#include "controller_modalidade.h"
#include "controller_editar_usuario.h"
#include "data_modalidade.h"
#include "data_autenticacao.h"
#include "data_usuario.h"
#include "data_cadastro_pendente.h"
#include "data_turma.h"
#include "data_graduacao.h"
#include "data_autenticacao.h"
#include "data_aluno.h"
#include "data_perfil.h"
#include "data_pagamento.h"

class MainInitializer
{
private:
  // CONEXAO COM BANCO
  Database *_database;
  // SESSAO
  Session *_session;
  // MENUS
  MenuInicial *_menuInicial;
  MenuCliente *_menuCliente;
  MenuProfessor *_menuProfessor;
  MenuAdministrador *_menuAdministrador;
  MenuOpcoesUsuario *_menuOpcoesUsuario;
  MenuCadastroPendente *_menuCadastroPendente;
  MenuCadastros *_menuCadastros;
  MenuOpcoesTurma *_menuOpcoesTurma;
  MenuOpcoesGraduacao *_menuOpcoesGraduacao;
  MenuOpcoesModalidade *_menuOpcoesModalidade;
  MenuEditarUsuario *_menuEditarUsuario;
  // CONTROLLERS
  ControllerAutenticacao *_controllerAutenticacao;
  ControllerOpcoesUsuario *_controllerOpcoesUsuario;
  ControllerCadastroPendente *_controllerCadastroPendente;
  ControllerTurma *_controllerTurma;
  ControllerGraduacao *_controllerGraduacao;
  ControllerModalidade *_controllerModalidade;
  ControllerEditarUsuario *_controllerEditarUsuario;
  // DATA
  DataModalidade *_dataModalidade;
  DataAutenticacao *_dataAutenticacao;
  DataUsuario *_dataUsuario;
  DataCadastroPendente *_dataCadastroPendente;
  DataTurma *_dataTurma;
  DataGraduacao *_dataGraduacao;
  DataAluno *_dataAluno;
  DataPerfil *_dataPerfil;
  DataPagamento *_dataPagamento;

  void initializeData();
  void initializeAutenticacao();
  void initializeUsuario();
  void initializeCadastroPendente();
  void initializeModalidade();
  void initializeTurma();
  void initializeGraduacao();
  void initializeAluno();
  void destroyData();
  void destroyAutenticacao();
  void destroyUsuario();
  void destroyCadastroPendente();
  void destroyModalidade();
  void destroyTurma();
  void destroyGraduacao();
  void destroyAluno();

public:
  MainInitializer();
  ~MainInitializer();
  bool initialize();
  void executar();
};

#endif