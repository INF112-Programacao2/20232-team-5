#ifndef INF112_MENU_H
#define INF112_MENU_H
#include <vector>
#include "global.h"
#include "opcao_menu.h"

class Menu
{
protected:
  std::vector<OpcaoMenu> _opcaoList;
  void exibir();
  virtual void inicializarOpcoes() = 0;

private:
  std::string _title;

public:
  Menu(std::string title);
  virtual RetornoController executar();
};

#endif
