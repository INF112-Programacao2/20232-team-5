#include "menu_opcoes_usuario.h"
#include "opcao_menu.h"
#include "global.h"
#include "controller_autenticacao.h"

MenuOpcoesUsuario::MenuOpcoesUsuario(std::string title, ControllerAutenticacao *controllerAutenticacao) : Menu(title), _controllerAutenticacao(controllerAutenticacao)
{
  inicializarOpcoes();
}

void MenuOpcoesUsuario::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Alternar Perfil", std::bind(&ControllerAutenticacao::alternaPerfil, _controllerAutenticacao)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}