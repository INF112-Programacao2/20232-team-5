#include "menu_opcoes_turma.h"
#include "opcao_menu.h"
#include "global.h"
#include "controller_turma.h"

MenuOpcoesTurma::MenuOpcoesTurma(std::string title, ControllerTurma *controllerTurma) : Menu(title), _controllerTurma(controllerTurma)
{
  inicializarOpcoes();
}

void MenuOpcoesTurma::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Cadastrar turma", std::bind(&ControllerTurma::realizaCadastro, _controllerTurma)));
  /*_opcaoList.push_back(OpcaoMenu("Listar turmas", std::bind(&ControllerTurma::listaTurmas, _controllerTurma)));*/
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}
