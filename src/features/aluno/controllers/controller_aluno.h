#ifndef INF112_CONTROLLER_ALUNO_H
#define INF112_CONTROLLER_ALUNO_H
#include "controller.h"
#include "global.h"
#include "session.h"
#include "data_aluno.h"
#include "data_graduacao.h"
#include "menu_acesso_aluno.h"

class ControllerAluno : public Controller
{
private:
  Session *_session;
  DataAluno *_dataAluno;
  DataGraduacao *_dataGraduacao;
  MenuAcessoAluno *_menuAcessoAluno;

public:
  ControllerAluno(Session *session, DataAluno *dataAluno, DataGraduacao *dataGraduacao, MenuAcessoAluno *menuAcessoAluno);
  RetornoController listaTodos();
  RetornoController listaAptos();
  RetornoController acessoAluno();
};

#endif