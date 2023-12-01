#include "data_usuario.h"

DataUsuario::DataUsuario(PGconn *conn)
{
  _conn = conn;
}

void DataUsuario::salvarSenha(int chaveUsu, std::string senha)
{
  // Mock
}