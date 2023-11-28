#ifndef INF112_CONTROLLER_USUARIO_H
#define INF112_CONTROLLER_USUARIO_H
#include "global.h"
#include "session.h"
#include <vector>

// Classe responsável por controlar as operações de autenticação

class ControllerUsuario
{
private:
  Session *_session;
  int escolhaPerfil();

public:
  ControllerUsuario(Session *session);
  RetornoController alternaPerfil();
  RetornoController trocaSenha();
};

#endif