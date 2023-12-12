#ifndef INF112_MENU_ACESSO_ALUNO_H
#define INF112_MENU_ACESSO_ALUNO_H

#include "menu.h"
#include "session.h"
#include "controller_acesso_aluno.h"

class MenuAcessoAluno : public Menu
{
protected:
  Session *_session;
  ControllerAcessoAluno *_controllerAcessoAluno;
  virtual void inicializarOpcoes();

public:
  MenuAcessoAluno(std::string title, Session *session, ControllerAcessoAluno *controllerAcessoAluno);
};

#endif