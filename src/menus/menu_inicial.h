#ifndef INF112_MENU_INICIAL_H
#define INF112_MENU_INICIAL_H
#include "menu.h"
#include "controller_login.h"

class MenuInicial : public Menu
{
protected:
  ControllerLogin *_controllerLogin;
  virtual void inicializarOpcoes();

public:
  MenuInicial(std::string title, ControllerLogin *controllerLogin);
};

#endif