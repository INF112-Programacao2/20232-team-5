#include "menu_cadastros.h"

MenuCadastros::MenuCadastros(std::string title, Session *session, MenuOpcoesGraduacao *menuOpcoesGraduacao,
                             MenuOpcoesTurma *menuOpcoesTurma, MenuOpcoesModalidade *menuOpcoesModalidade)
    : Menu(title), _session(session), _menuOpcoesGraduacao(menuOpcoesGraduacao), _menuOpcoesTurma(menuOpcoesTurma),
      _menuOpcoesModalidade(menuOpcoesModalidade)
{
  inicializarOpcoes();
}

void MenuCadastros::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Opções de Graduação", std::bind(&MenuOpcoesGraduacao::executar, _menuOpcoesGraduacao)));
  _opcaoList.push_back(OpcaoMenu("Opções de Turma", std::bind(&MenuOpcoesTurma::executar, _menuOpcoesTurma)));
  _opcaoList.push_back(OpcaoMenu("Opções de Modalidade", std::bind(&MenuOpcoesModalidade::executar, _menuOpcoesModalidade)));
  _opcaoList.push_back(OpcaoMenu("Logout", std::bind(logout)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}

