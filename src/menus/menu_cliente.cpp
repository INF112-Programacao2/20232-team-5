#include "menu_cliente.h"
#include "opcao_menu.h"

MenuCliente::MenuCliente(std::string title, Session *session) : Menu(title), _session(session)
{
  inicializarOpcoes();
}

void MenuCliente::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Deslogar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do sistema", std::bind(sair)));
}