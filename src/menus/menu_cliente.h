#ifndef INF112_MENU_CLIENTE_H
#define INF112_MENU_CLIENTE_H
#include "menu.h"
#include "global.h"
#include "session.h"
#include "menu_opcoes_usuario.h"
#include "controller_registrar_presenca.h"

class MenuCliente : public Menu
{
protected:
  Session *_session;
  MenuOpcoesUsuario *_menuOpcoesUsuario;
  ControllerRegistrarPresenca *_controllerRegistrarPresenca;
  virtual void inicializarOpcoes();

public:
  MenuCliente(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario, ControllerRegistrarPresenca *controllerRegistrarPresenca);
};

#endif