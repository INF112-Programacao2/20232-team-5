#ifndef INF112_DATA_USUARIO_H
#define INF112_DATA_USUARIO_H
#include <libpq-fe.h>
#include "usuario.h"

class DataUsuario
{
private:
  PGconn *_conn;

public:
  DataUsuario(PGconn *conn);
  void salvarSenha(int chaveUsu, std::string senha);
};

#endif