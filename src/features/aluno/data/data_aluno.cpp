#include "data_aluno.h"
#include "global.h"

DataAluno::DataAluno(Database *database) : _database(database) {}

void DataAluno::criaAluno(Aluno *aluno)
{
  std::string query = "INSERT INTO \"ALUNO\" (\"CHAVEUSU\", \"CHAVEGRD\", \"NUMAULAS\") VALUES ($1, $2, $3);";
  std::vector<std::string> params = {
      std::to_string(aluno->getChaveUsu()),
      std::to_string(aluno->getChaveGrd()),
      "0"};

  PGresult *res = _database->executar(query, params);
  PQclear(res);
}