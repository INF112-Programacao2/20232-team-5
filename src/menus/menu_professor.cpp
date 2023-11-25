#include "menu_professor.h"
#include "opcao_menu.h"

MenuProfessor::MenuProfessor(std::string title, Session *session) : Menu(title), _session(session)
{
  inicializarOpcoes();
}

void MenuProfessor::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Deslogar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do sistema", std::bind(sair)));
}