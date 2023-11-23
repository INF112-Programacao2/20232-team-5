#ifndef INF112_ALUNO_H
#define INF112_ALUNO_H
#include "global.h"
#include "session.h"

// Classe responsável por controlar as operações de autenticação

class ControllerAutenticacao
{
private:
  Session *_session;

public:
  ControllerAutenticacao(Session *session);
  RetornoController realizaCadastro();
};

#endif