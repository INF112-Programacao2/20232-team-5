#include "menu_aluno.h"

MenuAluno::MenuAluno(std::string title, Session *session, ControllerAluno *controllerAluno) : Menu(title), _session(session), _controllerAluno(controllerAluno)
{
  inicializarOpcoes();
}

void MenuAluno::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Listar todos", std::bind(&ControllerAluno::listaTodos, _controllerAluno)));
  _opcaoList.push_back(OpcaoMenu("Listar aptos a graduar", std::bind(&ControllerAluno::listaAptos, _controllerAluno)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}

RetornoController MenuAluno::executar()
{
  setTitle("Alunos - " + _session->getSelectedModalidade().getNome());
  return Menu::executar();
}