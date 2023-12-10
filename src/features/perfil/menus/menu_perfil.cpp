#include "menu_perfil.h"

MenuPerfil::MenuPerfil(std::string title, ControllerPerfil *controllerPerfil) : Menu(title), _controllerPerfil(controllerPerfil)
{
  inicializarOpcoes();
}

void MenuPerfil::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Voltar", voltar));
}