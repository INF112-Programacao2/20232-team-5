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

std::vector<Aluno> DataAluno::buscaListaAlunosAptos(int chaveMod)
{
  std::string query = "SELECT * FROM \"ALUNO\" a INNER JOIN \"USUARIO\" u ON u.\"CHAVEUSU\" = a.\"CHAVEUSU\" INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEGRD\" = a.\"CHAVEGRD\" WHERE a.\"NUMAULAS\" >= g.\"MINAULAS\" AND g.\"CHAVEMOD\" = $1;";
  std::vector<std::string> params = {std::to_string(chaveMod)};

  PGresult *res = _database->executar(query, params);
  std::vector<Aluno> listaAluno;
  for (int i = 0; i < PQntuples(res); i++)
    listaAluno.push_back(Aluno::fromDatabase(res, i));
  PQclear(res);
  return listaAluno;
}

// Busca aluno por chave do aluno e da graduação
Aluno *DataAluno::buscaAluno(int chaveAlu, int chaveMod)
{
  std::string query = "SELECT * FROM \"ALUNO\" a INNER JOIN \"USUARIO\" u ON a.\"CHAVEUSU\" = u.\"CHAVEUSU\" INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEGRD\" = a.\"CHAVEGRD\" WHERE \"CHAVEALU\" = $1 AND \"CHAVEMOD\" = $2;";
  std::vector<std::string> params = {
      std::to_string(chaveAlu),
      std::to_string(chaveMod),
  };

  PGresult *res = _database->executar(query, params);
  Aluno *aluno = nullptr;
  if (PQntuples(res))
    aluno = Aluno::fromDatabaseToPtr(res, 0);
  PQclear(res);
  return aluno;
}

// Busca aluno por chave do usuário e da graduação
Aluno *DataAluno::buscaAlunoByUsuario(int chaveUsu, int chaveMod)
{
  std::string query = "SELECT * FROM \"ALUNO\" a INNER JOIN \"USUARIO\" u ON a.\"CHAVEUSU\" = u.\"CHAVEUSU\" INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEGRD\" = a.\"CHAVEGRD\" WHERE u.\"CHAVEUSU\" = $1 AND \"CHAVEMOD\" = $2;";
  std::vector<std::string> params = {
      std::to_string(chaveUsu),
      std::to_string(chaveMod),
  };

  PGresult *res = _database->executar(query, params);
  Aluno *aluno = nullptr;
  if (PQntuples(res))
    aluno = Aluno::fromDatabaseToPtr(res, 0);
  PQclear(res);
  return aluno;
}

void DataAluno::realizaGraduacao(int chaveAlu, int chaveGrd)
{
  std::string query = "UPDATE \"ALUNO\" SET \"CHAVEGRD\" = $1, \"NUMAULAS\" = 0 WHERE \"CHAVEALU\" = $2";
  std::vector<std::string>
      params = {
          std::to_string(chaveGrd),
          std::to_string(chaveAlu),
      };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}