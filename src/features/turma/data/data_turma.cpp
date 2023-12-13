#include "data_turma.h"
#include <string>
#include <vector>
#include "global.h"
#include "database_error.h"
#include <exception>

DataTurma::DataTurma(Database *database)
{
  _database = database;
}

void DataTurma::cadastraTurma(Turma *turma)
{
  std::string insertQuery = "INSERT INTO public.\"TURMA\" "
                            "(\"CHAVEUSU\", \"CHAVEMOD\", \"HRINICIO\", \"HRFIM\", \"DIASSEMANA\") "
                            "VALUES ($1, $2, $3, $4, $5)";

  std::vector<std::string> params = {
      std::to_string(turma->getChaveUsu()),
      std::to_string(turma->getChaveMod()),
      turma->getHrInicio(),
      turma->getHrFim(),
      turma->getDiasSemana(),
  };
  PGresult *res = _database->executar(insertQuery, params);
  PQclear(res);
}

std::vector<Turma *> DataTurma::buscaTurmasModalidade(int chaveMod)
{
  std::string query = "SELECT T.\"CHAVETUR\", T.\"CHAVEUSU\", T.\"CHAVEMOD\", T.\"HRINICIO\", T.\"HRFIM\", T.\"DIASSEMANA\" "
                      "FROM \"TURMA\" T WHERE T.\"CHAVEMOD\" = $1";

  std::vector<std::string> params = {std::to_string(chaveMod)};
  PGresult *res;

  res = _database->executar(query, params);

  std::vector<Turma *> listaTurmas;
  for (int i = 0; i < PQntuples(res); i++)
  {
    Turma *turma = Turma::fromDatabaseToPtr(res, i);
    listaTurmas.push_back(turma);
  }

  PQclear(res);
  return listaTurmas;
}

void DataTurma::editarTurma(Turma *turma)
{
  std::string updateQuery = "UPDATE public.\"TURMA\" "
                            "SET \"CHAVEUSU\"=$1, \"CHAVEMOD\"=$2, \"HRINICIO\"=$3, \"HRFIM\"=$4, \"DIASSEMANA\"=$5 "
                            "WHERE \"CHAVETUR\"=$6";

  std::vector<std::string> params = {
      std::to_string(turma->getChaveUsu()),
      std::to_string(turma->getChaveMod()),
      turma->getHrInicio(),
      turma->getHrFim(),
      turma->getDiasSemana(),
      std::to_string(turma->getChaveTur()),
  };

  PGresult *res = _database->executar(updateQuery, params);
  PQclear(res);
}

void DataTurma::excluirTurma(int chaveTurma)
{
  std::string deleteQuery = "DELETE FROM public.\"TURMA\" "
                            "WHERE \"CHAVETUR\"=$1";

  std::vector<std::string> params = {
      std::to_string(chaveTurma),
  };

  PGresult *res = _database->executar(deleteQuery, params);
  PQclear(res);
}

void DataTurma::listarTurmas()
{
  std::string selectQuery = "SELECT \"CHAVETUR\", \"CHAVEUSU\", \"CHAVEMOD\", \"HRINICIO\", \"HRFIM\", \"DIASSEMANA\" "
                            "FROM public.\"TURMA\"";

  PGresult *res = _database->executar(selectQuery);
  int numTurmas = PQntuples(res);

  if (numTurmas == 0)
  {
    std::cout << "Nenhuma turma cadastrada!" << std::endl;
    PQclear(res);
    return;
  }

  std::cout << "Turmas cadastradas:" << std::endl;
  for (int i = 0; i < numTurmas; i++)
  {
    std::cout << "Chave: " << PQgetvalue(res, i, 0) << std::endl;
    std::cout << "Chave do usuário: " << PQgetvalue(res, i, 1) << std::endl;
    std::cout << "Chave da modalidade: " << PQgetvalue(res, i, 2) << std::endl;
    std::cout << "Horário de início: " << PQgetvalue(res, i, 3) << std::endl;
    std::cout << "Horário de fim: " << PQgetvalue(res, i, 4) << std::endl;
    std::cout << "Dias da semana: " << PQgetvalue(res, i, 5) << std::endl;
    std::cout << std::endl;
  }

  PQclear(res);
}

void DataTurma::presencaTurma(int chaveTurma)
{
  std::string selectQuery = "SELECT  u.\"CHAVEUSU\", u.\"NOME\", COUNT(p.\"CHAVEPRE\") AS \"DIAS\" FROM public.\"TURMA\" t INNER JOIN \"PRESENCA\" p ON p.\"CHAVETUR\" = t.\"CHAVETUR\" INNER JOIN public.\"ALUNO\" a ON a.\"CHAVEALU\" = p.\"CHAVEALU\" INNER JOIN \"USUARIO\" u ON u.\"CHAVEUSU\" = a.\"CHAVEUSU\" WHERE t.\"CHAVETUR\" = $1 GROUP BY u.\"CHAVEUSU\"";

  std::vector<std::string> params = {
      std::to_string(chaveTurma),
  };

  PGresult *res = _database->executar(selectQuery, params);
  int numAlunos = PQntuples(res);

  if (numAlunos == 0)
  {
    std::cout << "Nenhum aluno cadastrado!" << std::endl;
    PQclear(res);
    return;
  }
  finalizarTela();
  std::cout << "Alunos cadastrados:" << std::endl
            << std::endl;
  for (int i = 0; i < numAlunos; i++)
  {
    std::cout << "Chave do usuário: " << Database::value(res, i, "CHAVEUSU") << std::endl;
    std::cout << "Nome: " << Database::value(res, i, "NOME") << std::endl;
    std::cout << "Dias presente: " << Database::value(res, i, "DIAS") << std::endl;
    std::cout << std::endl
              << std::endl;
  }

  PQclear(res);
}

Turma *DataTurma::buscaTurma(int chaveTur)
{
  std::string query = "SELECT * FROM \"TURMA\" WHERE \"CHAVETUR\" = $1";
  std::vector<std::string> params = {std::to_string(chaveTur)};

  PGresult *res = _database->executar(query, params);
  Turma *t = nullptr;
  if (PQntuples(res))
    t = Turma::fromDatabaseToPtr(res, 0);
  return t;
}