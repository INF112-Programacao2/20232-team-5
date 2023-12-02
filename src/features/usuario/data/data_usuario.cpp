#include "data_usuario.h"

DataUsuario::DataUsuario(PGconn *conn)
{
  _conn = conn;
}

void DataUsuario::salvarSenha(int chaveUsu, std::string senha)
{
  // Mock
}

Usuario *DataUsuario::buscaUsuarioByChave(int chaveUsu)
{
  // Mock
  // return nullptr;
  Usuario *u = new Usuario(1, "João", "Joaozin", "17/04/2003", "10164444602", "20834320", 'M', "joaovitor", "senha123");
  return u;
}