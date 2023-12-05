#include "database.h"

// Classe base que controla as operações relacionadas ao banco de dados

Database::Database(std::string connectionString)
{
  _connectionString = connectionString;
}

bool Database::initializeConn()
{
  _conn = PQconnectdb(_connectionString.c_str());
  if (PQstatus(_conn) != CONNECTION_OK)
  {
    std::cerr << "Erro na conexão com o banco de dados: " << PQerrorMessage(_conn) << std::endl;
    PQfinish(_conn);
    _conn = nullptr;
    return false;
  }
  return true;
}

Database::~Database()
{
  {
    if (_conn)
    {
      PQfinish(_conn);
      _conn = nullptr;
    }
  }
}

// Sem parametros
PGresult *Database::executar(std::string &query)
{
  if (!_conn)
  {
    throw DatabaseError("Conexão inválida.");
  }

  PGresult *result = PQexec(_conn, query.c_str());

  if (PQresultStatus(result) != PGRES_TUPLES_OK && PQresultStatus(result) != PGRES_COMMAND_OK)
  {
    std::string errorMsg = PQresultErrorMessage(result);
    PQclear(result);
    throw DatabaseError(errorMsg);
  }

  return result;
}

// Com parametros
PGresult *Database::executar(std::string &query, std::vector<std::string> &params)
{
  if (!_conn)
  {
    throw DatabaseError("Conexão inválida.");
  }

  const char *paramValues[params.size()];

  for (int i = 0; i < params.size(); ++i)
    paramValues[i] = params[i] != "NULL" ? params[i].c_str() : NULL;

  PGresult *result = PQexecParams(_conn, query.c_str(), (int)params.size(), nullptr, paramValues, nullptr, nullptr, 0);

  if (PQresultStatus(result) != PGRES_TUPLES_OK && PQresultStatus(result) != PGRES_COMMAND_OK)
  {
    std::string errorMsg = PQresultErrorMessage(result);
    PQclear(result);
    throw DatabaseError(errorMsg);
  }

  return result;
}