#include "opcao_menu.h"

OpcaoMenu::OpcaoMenu(std::string label, std::function<RetornoController()> action) : _label(label), _action(action) {}

std::string OpcaoMenu::getLabel()
{
  return _label;
}

RetornoController OpcaoMenu::executar()
{
  return _action();
}