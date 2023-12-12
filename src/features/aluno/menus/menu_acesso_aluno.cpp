#include "menu_acesso_aluno.h"

MenuAcessoAluno::MenuAcessoAluno(std::string title, Session *session, ControllerAcessoAluno *controllerAcessoAluno) : Menu(title), _session(session), _controllerAcessoAluno(controllerAcessoAluno)
{
  inicializarOpcoes();
}

void MenuAcessoAluno::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Ver Dados", std::bind(&ControllerAcessoAluno::verDados, _controllerAcessoAluno)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}