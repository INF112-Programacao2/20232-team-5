#ifndef INF112_MENU_EDITAR_USUARIO_H
#define INF112_MENU_EDITAR_USUARIO_H
#include "menu.h"
#include "controller_editar_usuario.h"

class MenuEditarUsuario : public Menu
{
protected:
  ControllerEditarUsuario *_controllerEditarUsuario;
  virtual void inicializarOpcoes();

public:
  MenuEditarUsuario(std::string title, ControllerEditarUsuario *controllerEditarUsuario);
};

#endif