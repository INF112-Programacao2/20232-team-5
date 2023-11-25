#ifndef INF112_MENU_CLIENTE_H
#define INF112_MENU_CLIENTE_H
#include "menu.h"
#include "global.h"
#include "session.h"

class MenuCliente : public Menu
{
protected:
  Session *_session;
  virtual void inicializarOpcoes();

public:
  MenuCliente(std::string title, Session *session);
};

#endif