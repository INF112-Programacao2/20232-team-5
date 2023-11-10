#include "opcao_menu.h"

OpcaoMenu::OpcaoMenu(std::string label, IController *controller) : _label(label), _controller(controller) {}

std::string OpcaoMenu::getLabel()
{
  return _label;
}

IController *OpcaoMenu::getController()
{
  return _controller;
}

int OpcaoMenu::executar()
{
  return _controller->executar();
}