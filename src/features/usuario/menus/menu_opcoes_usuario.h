#ifndef INF112_MENU_OPCOES_USUARIO_H
#define INF112_MENU_OPCOES_USUARIO_H
#include "menu.h"
#include "session.h"
#include "controller_usuario.h"

class MenuOpcoesUsuario : public Menu
{
protected:
  Session *_session;
  ControllerUsuario *_controllerUsuario;
  virtual void inicializarOpcoes();

public:
  MenuOpcoesUsuario(std::string title, ControllerUsuario *controllerUsuario);
};

#endif