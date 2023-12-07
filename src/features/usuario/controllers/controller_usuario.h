#ifndef INF112_CONTROLLER_USUARIO_H
#define INF112_CONTROLLER_USUARIO_H
#include "global.h"
#include "session.h"
#include <vector>
#include "data_usuario.h"

// Classe responsável por controlar as operações de autenticação

class ControllerUsuario
{
private:
  Session *_session;
  DataUsuario *_dataUsuario;
  int escolhaPerfil();
  std::string getTipoStr(TipoPerfil tipo);

public:
  ControllerUsuario(Session *session, DataUsuario *dataUsuario);
  RetornoController alternaPerfil();
  RetornoController trocaSenha();
};

#endif