#ifndef INF112_CONTROLLER_ACESSO_ALUNO_H
#define INF112_CONTROLLER_ACESSO_ALUNO_H
#include "controller.h"
#include "global.h"
#include "session.h"
#include "data_aluno.h"
#include "data_graduacao.h"
#include "data_modalidade.h"

class ControllerAcessoAluno : public Controller
{
private:
  Session *_session;
  DataAluno *_dataAluno;
  DataGraduacao *_dataGraduacao;
  DataModalidade *_dataModalidade;

public:
  ControllerAcessoAluno(Session *session, DataAluno *dataAluno, DataGraduacao *dataGraduacao, DataModalidade *dataModalidade);
  RetornoController verDados();
  RetornoController graduacao();
};

#endif