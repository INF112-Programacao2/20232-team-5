#include "data_turma.h"

DataTurma::DataTurma(PGconn *conn)
{
  _conn = conn;
}

void DataTurma::cadastraTurma(Turma *turma)
{
  const char *insertQuery = "INSERT INTO public.\"TURMA\" "
                            "(\"CHAVEUSU\", \"CHAVEMOD\", \"HRINICIO\", \"HRFIM\", \"DIASSEMANA\") "
                            "VALUES ($1, $2, $3, $4, $5)";

  std::cout << *insertQuery << std::endl;

  const char *const paramValues[5] = {
      std::to_string(turma->getChavePes()).c_str(),
      std::to_string(turma->getChaveMod()).c_str(),
      turma->getHrInicio().c_str(),
      turma->getHrFim().c_str(),
      turma->getDiasSemana().c_str()
  };

  PGresult *res = PQexecParams(_conn, insertQuery, 5, NULL, paramValues, NULL, NULL, 0);
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    std::cout << "PQexecParams failed: " << PQresultErrorMessage(res)
              << std::endl;
    std::cout << PQresultStatus(res) << std::endl;
  }

  PQclear(res);
}
