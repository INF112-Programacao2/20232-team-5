#ifndef INF112_MENU_H
#define INF112_MENU_H
#include <vector>
#include "controller.h"
#include "global.h"
#include "opcao_menu.h"

class Menu : public IController
{
protected:
  std::vector<OpcaoMenu> _opcaoList;

private:
  std::string _title;
  virtual void exibir();

public:
  Menu(std::string title);
  ~Menu();
  virtual RetornoController executar();
  virtual void initializeOpcaoList() = 0;
  virtual void destroyOpcaoList() = 0;
};

#endif
