#ifndef INF112_DATABASE_H
#define INF112_DATABASE_H
#include <libpq-fe.h>
#include <string>
#include <iostream>
#include <vector>
#include "database_error.h"

// Classe base que controla as operações relacionadas ao banco de dados

class Database
{
private:
  std::string _connectionString;
  PGconn *_conn;

public:
  Database(std::string connectionString);
  ~Database();
  bool initializeConn();
  // Executa query sem parâmetros
  PGresult *executar(std::string &query);
  // Executa query com parâmetros
  PGresult *executar(std::string &query, std::vector<std::string> &params);
  // Persiste as alterações no banco de dados
  void commit();
  // Desfaz as alterações no banco de dados
  void rollback();
  // Obtém valor de certo campo em um resultado do banco de dados
  static std::string value(PGresult *res, int row, std::string fieldName);
};

#endif