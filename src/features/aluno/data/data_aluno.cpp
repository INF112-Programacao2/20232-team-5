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

std::vector<Aluno> DataAluno::buscaListaAlunos(int chaveMod)
{
  std::string query = "SELECT * FROM \"ALUNO\" a INNER JOIN \"USUARIO\" u ON u.\"CHAVEUSU\" = a.\"CHAVEUSU\" INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEGRD\" = a.\"CHAVEGRD\" WHERE g.\"CHAVEMOD\" = $1;";
  std::vector<std::string> params = {std::to_string(chaveMod)};

  PGresult *res = _database->executar(query, params);
  std::vector<Aluno> listaAluno;
  for (int i = 0; i < PQntuples(res); i++)
    listaAluno.push_back(Aluno::fromDatabase(res, i));
  PQclear(res);
  return listaAluno;
}