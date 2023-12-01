#include "data_modalidade.h"

DataModalidade::DataModalidade(PGconn *conn)
{
  _conn = conn;
}

std::vector<Modalidade> DataModalidade::leListaModalidade()
{
  // Retorno mockado
  return {
      Modalidade(1, "Judô"),
      Modalidade(2, "Karatê"),
  };
}