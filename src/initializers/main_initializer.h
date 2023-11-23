#ifndef INF112_MAIN_INITIALIZER_H
#define INF112_MAIN_INITIALIZER_H
#include "menu_inicial.h"
#include "controller_autenticacao.h"
#include "session.h"

class MainInitializer
{
private:
  MenuInicial *_menuInicial;
  ControllerAutenticacao *_controllerAutenticacao;
  Session *_session;

public:
  MainInitializer();
  ~MainInitializer();
  void executar();
};

#endif