#include "menu_perfil.h"

MenuPerfil::MenuPerfil(std::string title, ControllerPerfil *controllerPerfil) : Menu(title), _controllerPerfil(controllerPerfil)
{
  inicializarOpcoes();
}

void MenuPerfil::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Listar todos", std::bind(&ControllerPerfil::listaPerfilUsuario, _controllerPerfil)));
  _opcaoList.push_back(OpcaoMenu("Adicionar perfil", std::bind(&ControllerPerfil::adicionaPerfilUsuario, _controllerPerfil)));
  _opcaoList.push_back(OpcaoMenu("Remover perfil", std::bind(&ControllerPerfil::deletaPerfilUsuario, _controllerPerfil)));
  _opcaoList.push_back(OpcaoMenu("Voltar", voltar));
}