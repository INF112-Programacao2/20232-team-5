#ifndef INF112_CONTROLLER_ALUNO_H
#define INF112_CONTROLLER_ALUNO_H
#include "controller.h"
#include "global.h"
#include "session.h"
#include "data_aluno.h"
#include "data_graduacao.h"

class ControllerAluno : public Controller
{
private:
  Session *_session;
  DataAluno *_dataAluno;
  DataGraduacao *_dataGraduacao;

public:
  ControllerAluno(Session *session, DataAluno *dataAluno, DataGraduacao *dataGraduacao);
  RetornoController listaTodos();
  RetornoController listaAptos();
};

#endif