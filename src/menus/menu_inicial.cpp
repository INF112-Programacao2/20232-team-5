#include "menu_inicial.h"
#include "opcao_menu.h"
#include "controller_sair.h"
#include "controller_login.h"

MenuInicial::MenuInicial(std::string title) : Menu(title)
{
  initializeOpcaoList();
}

MenuInicial::~MenuInicial()
{
  destroyOpcaoList();
}

void MenuInicial::initializeOpcaoList()
{
  _opcaoList.push_back(OpcaoMenu("Login", new ControllerLogin()));
  _opcaoList.push_back(OpcaoMenu("Sair", new ControllerSair()));
}

void MenuInicial::destroyOpcaoList()
{
  for (auto option : _opcaoList)
  {
    delete option.getController();
  }
}