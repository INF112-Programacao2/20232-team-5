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
  _opcaoList.push_back(OpcaoMenu("Editar turma", std::bind(&ControllerTurma::realizaEdicao, _controllerTurma)));
  _opcaoList.push_back(OpcaoMenu("Excluir turma", std::bind(&ControllerTurma::realizaRemocao, _controllerTurma)));
  _opcaoList.push_back(OpcaoMenu("Listar turmas", std::bind(&ControllerTurma::realizaListagem, _controllerTurma)));
  _opcaoList.push_back(OpcaoMenu("Visualizar presença", std::bind(&ControllerTurma::realizaPresenca, _controllerTurma)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}
