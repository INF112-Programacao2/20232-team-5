#ifndef INF112_CONTROLLER_DADOS_ALUNO_H
#define INF112_CONTROLLER_DADOS_ALUNO_H
#include "global.h"
#include "session.h"
#include "controller.h"
#include "data_aluno.h"
#include "data_modalidade.h"
#include "data_graduacao.h"

// Classe responsável por controlar as operações de autenticação

class ControllerDadosAluno : public Controller
{
private:
  Session *_session;
  DataModalidade *_dataModalidade;
  DataGraduacao *_dataGraduacao;
  DataAluno *_dataAluno;

public:
  ControllerDadosAluno(Session *session, DataModalidade *dataModalidade, DataGraduacao *dataGraduacao, DataAluno *dataAluno);
  RetornoController mostraDados();
};

#endif