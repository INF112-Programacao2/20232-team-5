#ifndef INF112_MENU_PERFIL_H
#define INF112_MENU_PERFIL_H
#include "menu.h"
#include "controller_perfil.h"

class MenuPerfil : public Menu
{
protected:
  ControllerPerfil *_controllerPerfil;
  virtual void inicializarOpcoes();

public:
  MenuPerfil(std::string title, ControllerPerfil *controllerPerfil);
};

#endif