#ifndef INF112_MENU_PROFESSOR_H
#define INF112_MENU_PROFESSOR_H
#include "menu.h"
#include "session.h"
#include "global.h"
#include "menu_opcoes_usuario.h"

class MenuProfessor : public Menu
{
protected:
  Session *_session;
  MenuOpcoesUsuario *_menuOpcoesUsuario;
  virtual void inicializarOpcoes();

public:
  MenuProfessor(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario);
};

#endif