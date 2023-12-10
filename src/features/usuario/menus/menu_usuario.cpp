#include "menu_usuario.h"

MenuUsuario::MenuUsuario(std::string title, ControllerUsuario *controllerUsuario) : Menu(title), _controllerUsuario(controllerUsuario)
{
  inicializarOpcoes();
}

void MenuUsuario::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Listar Todos", std::bind(&ControllerUsuario::listaTodos, _controllerUsuario)));
  _opcaoList.push_back(OpcaoMenu("Ver Dados", std::bind(&ControllerUsuario::verDados, _controllerUsuario)));
  _opcaoList.push_back(OpcaoMenu("Editar Dados", std::bind(&ControllerUsuario::editarDados, _controllerUsuario)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}