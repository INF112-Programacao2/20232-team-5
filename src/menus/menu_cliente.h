#ifndef INF112_MENU_CLIENTE_H
#define INF112_MENU_CLIENTE_H
#include "menu.h"
#include "global.h"
#include "session.h"
#include "menu_opcoes_usuario.h"

class MenuCliente : public Menu
{
protected:
  Session *_session;
  MenuOpcoesUsuario *_menuOpcoesUsuario;
  virtual void inicializarOpcoes();

public:
  MenuCliente(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario);
};

#endif