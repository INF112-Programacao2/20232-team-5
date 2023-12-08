#include "data_usuario.h"
#include <string>
#include <libpq-fe.h>

DataUsuario::DataUsuario(Database *database)
{
  _database = database;
}

void DataUsuario::salvarSenha(int chaveUsu, std::string senha)
{
  std::string query = "UPDATE \"USUARIO\" SET \"SENHA\" = $1;";
  std::vector<std::string> params = {
      senha,
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

Usuario *DataUsuario::buscaUsuarioByChave(int chaveUsu)
{
  std::string query = "SELECT * FROM \"USUARIO\" WHERE \"CHAVEUSU\" = $1";
  std::vector<std::string> params = {
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  Usuario *u = nullptr;
  if (PQntuples(res))
    u = Usuario::fromDatabase(res, 0);
  PQclear(res);
  return u;
}

void DataUsuario::criaUsuario(Usuario *usuario)
{
  // Mock
}