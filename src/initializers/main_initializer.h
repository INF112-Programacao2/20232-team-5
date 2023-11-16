#ifndef INF112_MAIN_INITIALIZER_H
#define INF112_MAIN_INITIALIZER_H
#include "menu_inicial.h"
#include "controller_login.h"

class MainInitializer
{
private:
  MenuInicial *_menuInicial;
  ControllerLogin *_controllerLogin;

public:
  MainInitializer();
  ~MainInitializer();
  void executar();
};

#endif