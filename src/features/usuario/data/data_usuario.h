#ifndef INF112_DATA_USUARIO_H
#define INF112_DATA_USUARIO_H
#include "database.h"
#include "usuario.h"

class DataUsuario
{
private:
  Database *_database;

public:
  DataUsuario(Database *database);
  void salvarSenha(int chaveUsu, std::string senha);
  Usuario *buscaUsuarioByChave(int chaveUsu);
};

#endif