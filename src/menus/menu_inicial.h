#ifndef INF112_MENU_INICIAL_H
#define INF112_MENU_INICIAL_H
#include "menu.h"

class MenuInicial : public Menu
{
public:
  MenuInicial(std::string title);
  ~MenuInicial();
  virtual void initializeOpcaoList();
  virtual void destroyOpcaoList();
};

#endif