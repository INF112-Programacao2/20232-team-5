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
  MenuInicial *_menuInicial;
  ControllerAutenticacao *_controllerAutenticacao;
  DataModalidade *_dataModalidade;
  DataAutenticacao *_dataAutenticacao;
  MenuCliente *_menuCliente;
  MenuProfessor *_menuProfessor;
  MenuAdministrador *_menuAdministrador;
  void initializeAutenticacao();
  void initializeModalidade();
  void destroyAutenticacao();
  void destroyModalidade();

public:
  MainInitializer();
  ~MainInitializer();
  void executar();
};

#endif