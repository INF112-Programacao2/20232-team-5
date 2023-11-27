#ifndef INF112_MENU_ADMINISTRADOR_H
#define INF112_MENU_ADMINISTRADOR_H
#include "menu.h"
#include "global.h"
#include "session.h"
#include "menu_opcoes_usuario.h"

class MenuAdministrador : public Menu
{
protected:
  Session *_session;
  MenuOpcoesUsuario *_menuOpcoesUsuario;
  virtual void inicializarOpcoes();

public:
  MenuAdministrador(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario);
};

#endif