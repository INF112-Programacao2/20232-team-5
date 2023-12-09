#include "menu_editar_usuario.h"

MenuEditarUsuario::MenuEditarUsuario(std::string title, ControllerEditarUsuario *controllerEditarUsuario) : Menu(title), _controllerEditarUsuario(controllerEditarUsuario)
{
  inicializarOpcoes();
}

void MenuEditarUsuario::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Editar nome", std::bind(&ControllerEditarUsuario::editarNome, _controllerEditarUsuario)));
  _opcaoList.push_back(OpcaoMenu("Editar apelido", std::bind(&ControllerEditarUsuario::editarApelido, _controllerEditarUsuario)));
  _opcaoList.push_back(OpcaoMenu("Editar data de nascimento", std::bind(&ControllerEditarUsuario::editarDtNascimento, _controllerEditarUsuario)));
  _opcaoList.push_back(OpcaoMenu("Editar CPF", std::bind(&ControllerEditarUsuario::editarCpf, _controllerEditarUsuario)));
  _opcaoList.push_back(OpcaoMenu("Editar sexo", std::bind(&ControllerEditarUsuario::editarSexo, _controllerEditarUsuario)));
  _opcaoList.push_back(OpcaoMenu("Editar login", std::bind(&ControllerEditarUsuario::editarLogin, _controllerEditarUsuario)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}
