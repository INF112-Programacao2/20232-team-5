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

  std::cout << insertQuery << std::endl;

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