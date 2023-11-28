#include "menu_opcoes_usuario.h"
#include "opcao_menu.h"
#include "global.h"
#include "controller_autenticacao.h"

MenuOpcoesUsuario::MenuOpcoesUsuario(std::string title, ControllerUsuario *controllerUsuario) : Menu(title), _controllerUsuario(controllerUsuario)
{
  inicializarOpcoes();
}

void MenuOpcoesUsuario::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Alternar perfil", std::bind(&ControllerUsuario::alternaPerfil, _controllerUsuario)));
  _opcaoList.push_back(OpcaoMenu("Trocar senha", std::bind(&ControllerUsuario::alternaPerfil, _controllerUsuario)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}