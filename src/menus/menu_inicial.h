#ifndef INF112_MENU_INICIAL_H
#define INF112_MENU_INICIAL_H
#include "menu.h"
#include "global.h"
#include "controller_autenticacao.h"

class MenuInicial : public Menu
{
protected:
  ControllerAutenticacao *_controllerAutenticacao;
  virtual void inicializarOpcoes();

public:
  MenuInicial(std::string title, ControllerAutenticacao *controllerAutenticacao);
};

#endif