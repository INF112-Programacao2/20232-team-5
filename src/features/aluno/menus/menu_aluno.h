#ifndef INF112_MENU_ALUNO_H
#define INF112_MENU_ALUNO_H

#include "menu.h"
#include "session.h"
#include "controller_aluno.h"

class MenuAluno : public Menu
{
protected:
  Session *_session;
  ControllerAluno *_controllerAluno;
  virtual void inicializarOpcoes();

public:
  MenuAluno(std::string title, Session *session, ControllerAluno *controllerAluno);
  virtual RetornoController executar() override;
};

#endif