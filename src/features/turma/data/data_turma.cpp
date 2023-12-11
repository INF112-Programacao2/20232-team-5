#include "data_turma.h"
#include <string>
#include <vector>
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

  try
  {
    PGresult *res = _database->executar(insertQuery, params);
    PQclear(res);
  }
  catch (DatabaseError e)
  {
    std::cerr << e.what() << std::endl;
  }
  catch (std::exception e)
  {
    std::cerr << "Ocorreu um erro inesperado!" << std::endl;
    std::cerr << e.what() << std::endl;
  }
}

std::vector<Turma*> DataTurma::buscaTurmasModalidade(int chaveMod)
{
  std::string query = "SELECT * FROM \"TURMA\" WHERE \"CHAVEMOD\" = $1";

  std::vector<std::string> params = {std::to_string(chaveMod)};

  PGresult *res = _database->executar(query, params);
  std::vector<Turma*> listaTurma;

  for (int i = 0; i < PQntuples(res); i++)
    listaTurma.push_back(Turma::fromDatabase(res, i));

  PQclear(res);
  return listaTurma;
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

  try
  {
    PGresult *res = _database->executar(updateQuery, params);
    PQclear(res);
  }
  catch (DatabaseError e)
  {
    std::cerr << e.what() << std::endl;
  }
  catch (std::exception e)
  {
    std::cerr << "Ocorreu um erro inesperado!" << std::endl;
    std::cerr << e.what() << std::endl;
  }
}

void DataTurma::excluirTurma(int chaveTurma)
{
  std::string deleteQuery = "DELETE FROM public.\"TURMA\" "
                            "WHERE \"CHAVETUR\"=$1";

  std::vector<std::string> params = {
      std::to_string(chaveTurma),
  };

  try
  {
    PGresult *res = _database->executar(deleteQuery, params);
    PQclear(res);
  }
  catch (DatabaseError e)
  {
    std::cerr << e.what() << std::endl;
  }
  catch (std::exception e)
  {
    std::cerr << "Ocorreu um erro inesperado!" << std::endl;
    std::cerr << e.what() << std::endl;
  }
}

void DataTurma::listarTurmas()
{
  std::string selectQuery = "SELECT \"CHAVETUR\", \"CHAVEUSU\", \"CHAVEMOD\", \"HRINICIO\", \"HRFIM\", \"DIASSEMANA\" "
                            "FROM public.\"TURMA\"";

  try
  {
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
  catch (DatabaseError e)
  {
    std::cerr << e.what() << std::endl;
  }
  catch (std::exception e)
  {
    std::cerr << "Ocorreu um erro inesperado!" << std::endl;
    std::cerr << e.what() << std::endl;
  }
}

void DataTurma::presencaTurma(int chaveTurma)
{
  std::string selectQuery = "SELECT \"CHAVEUSU\", \"NOME\", \"PRESENCA\" "
                            "FROM public.\"TURMA\" t INNER JOIN public.\"USUARIO\" u ON u.\"CHAVEUSU\" = t.\"CHAVEUSU\" "
                            "INNER JOIN public.\"ALUNO\" a ON a.\"CHAVEUSU\" = u.\"CHAVEUSU\" "
                            "INNER JOIN public.\"GRADUACAO\" g ON g.\"CHAVEGRD\" = a.\"CHAVEGRD\" "
                            "INNER JOIN public.\"MODALIDADE\" m ON m.\"CHAVEMOD\" = g.\"CHAVEMOD\" "
                            "WHERE t.\"CHAVETURMA\" = $1";

  std::vector<std::string> params = {
      std::to_string(chaveTurma),
  };

  try
  {
    PGresult *res = _database->executar(selectQuery, params);
    int numAlunos = PQntuples(res);

    if (numAlunos == 0)
    {
      std::cout << "Nenhum aluno cadastrado!" << std::endl;
      PQclear(res);
      return;
    }

    std::cout << "Alunos cadastrados:" << std::endl;
    for (int i = 0; i < numAlunos; i++)
    {
      std::cout << "Chave do usuário: " << PQgetvalue(res, i, 0) << std::endl;
      std::cout << "Nome: " << PQgetvalue(res, i, 1) << std::endl;
      std::cout << "Presença: " << PQgetvalue(res, i, 2) << std::endl;
      std::cout << std::endl;
    }

    PQclear(res);
  }
  catch (DatabaseError e)
  {
    std::cerr << e.what() << std::endl;
  }
  catch (std::exception e)
  {
    std::cerr << "Ocorreu um erro inesperado!" << std::endl;
    std::cerr << e.what() << std::endl;
  }
}