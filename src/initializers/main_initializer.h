#ifndef INF112_MAIN_INITIALIZER_H
#define INF112_MAIN_INITIALIZER_H
#include "menu_inicial.h"
#include "controller_autenticacao.h"
#include "session.h"
#include "data_modalidade.h"
#include "data_autenticacao.h"
#include "menu_cliente.h"
#include "menu_professor.h"
#include "menu_administrador.h"

class MainInitializer
{
private:
  Session *_session;
  // MENUS
  MenuInicial *_menuInicial;
  MenuCliente *_menuCliente;
  MenuProfessor *_menuProfessor;
  MenuAdministrador *_menuAdministrador;
  MenuOpcoesUsuario *_menuOpcoesUsuario;
  // CONTROLLERS
  ControllerAutenticacao *_controllerAutenticacao;
  // DATA
  DataModalidade *_dataModalidade;
  DataAutenticacao *_dataAutenticacao;
  void initializeAutenticacao();
  void initializeUsuario();
  void initializeModalidade();
  void destroyAutenticacao();
  void destroyUsuario();
  void destroyModalidade();

public:
  MainInitializer();
  ~MainInitializer();
  void executar();
};

#endif