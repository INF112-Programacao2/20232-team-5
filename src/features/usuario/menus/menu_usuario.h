#ifndef INF112_MENU_USUARIO_H
#define INF112_MENU_USUARIO_H
#include "menu.h"
#include "menu_perfil.h"
#include "controller_usuario.h"

class MenuUsuario : public Menu
{
protected:
  ControllerUsuario *_controllerUsuario;

  virtual void inicializarOpcoes();

public:
  MenuUsuario(std::string title, ControllerUsuario *controllerUsuario);
};

#endif