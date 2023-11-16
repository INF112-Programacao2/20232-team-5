#ifndef INF112_OPCAOMENU_H
#define INF112_OPCAOMENU_H
#include <string>
#include "opcao_menu.h"
#include "global.h"
#include <functional>

class OpcaoMenu
{
private:
  std::string _label;
  std::function<RetornoController()> _action;

public:
  OpcaoMenu(std::string label, std::function<RetornoController()> action);
  std::string getLabel();
  int executar();
};

#endif
