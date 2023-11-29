#include "menu_administrador.h"
#include "opcao_menu.h"

MenuAdministrador::MenuAdministrador(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario, MenuCadastroPendente *menuCadastroPendente) : Menu(title), _session(session), _menuOpcoesUsuario(menuOpcoesUsuario), _menuCadastroPendente(menuCadastroPendente)
{
  inicializarOpcoes();
}

void MenuAdministrador::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Cadastros Pendentes", std::bind(&MenuCadastroPendente::executar, _menuCadastroPendente)));
  _opcaoList.push_back(OpcaoMenu("Opções do Usuário", std::bind(&MenuOpcoesUsuario::executar, _menuOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Logout", std::bind(logout)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}