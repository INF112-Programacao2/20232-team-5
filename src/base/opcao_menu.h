#ifndef INF112_OPCAOMENU_H
#define INF112_OPCAOMENU_H
#include <string>
#include "opcao_menu.h"
#include "controller.h"

class OpcaoMenu
{
private:
  std::string _label;
  IController *_controller;

public:
  OpcaoMenu(std::string label, IController *controller);
  std::string getLabel();
  IController *getController();
  int executar();
};

#endif
