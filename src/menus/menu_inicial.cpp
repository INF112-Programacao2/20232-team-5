#include "menu_inicial.h"
#include "opcao_menu.h"

MenuInicial::MenuInicial(std::string title, ControllerAutenticacao *controllerAutenticacao) : Menu(title), _controllerAutenticacao(controllerAutenticacao)
{
  inicializarOpcoes();
}

void MenuInicial::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Cadastro", std::bind(&ControllerAutenticacao::realizaCadastro, _controllerAutenticacao)));
  _opcaoList.push_back(OpcaoMenu("Sair", std::bind(sair)));
}