#include "menu_administrador.h"
#include "opcao_menu.h"

MenuAdministrador::MenuAdministrador(std::string title, Session *session) : Menu(title), _session(session)
{
  inicializarOpcoes();
}

void MenuAdministrador::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Deslogar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do sistema", std::bind(sair)));
}