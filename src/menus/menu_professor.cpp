#include "menu_professor.h"
#include "opcao_menu.h"

MenuProfessor::MenuProfessor(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario, ControllerEscolheModalidade *controllerEscolheModalidade) : Menu(title), _session(session), _menuOpcoesUsuario(menuOpcoesUsuario), _controllerEscolheModalidade(controllerEscolheModalidade)
{
  inicializarOpcoes();
}

void MenuProfessor::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Alunos", std::bind(&ControllerEscolheModalidade::entraMenuAlunos, _controllerEscolheModalidade)));
  _opcaoList.push_back(OpcaoMenu("Opções do Usuário", std::bind(&MenuOpcoesUsuario::executar, _menuOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Logout", std::bind(logout)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}