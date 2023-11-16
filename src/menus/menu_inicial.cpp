#include "menu_inicial.h"
#include "opcao_menu.h"
#include "controller_login.h"

MenuInicial::MenuInicial(std::string title, ControllerLogin *controllerLogin) : Menu(title), _controllerLogin(controllerLogin)
{
  inicializarOpcoes();
}

void MenuInicial::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Login", std::bind(&ControllerLogin::executar, _controllerLogin)));
  _opcaoList.push_back(OpcaoMenu("Sair", std::bind(sair)));
}