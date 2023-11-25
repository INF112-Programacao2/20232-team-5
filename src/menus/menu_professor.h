#ifndef INF112_MENU_PROFESSOR_H
#define INF112_MENU_PROFESSOR_H
#include "menu.h"
#include "session.h"
#include "global.h"

class MenuProfessor : public Menu
{
protected:
  Session *_session;
  virtual void inicializarOpcoes();

public:
  MenuProfessor(std::string title, Session *session);
};

#endif