#ifndef INF112_CONTROLLER_ESCOLHE_MODALIDADE_H
#define INF112_CONTROLLER_ESCOLHE_MODALIDADE_H
#include "controller.h"
#include "global.h"
#include "session.h"
#include "menu_aluno.h"
#include "data_modalidade.h"

class ControllerEscolheModalidade : public Controller
{
private:
  Session *_session;
  DataModalidade *_dataModalidade;
  MenuAluno *_menuAluno;

public:
  ControllerEscolheModalidade(Session *session, DataModalidade *dataModalidade, MenuAluno *menuAluno);
  RetornoController entraMenuAlunos();
};

#endif