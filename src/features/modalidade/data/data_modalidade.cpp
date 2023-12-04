#include "data_modalidade.h"

DataModalidade::DataModalidade(Database *database)
{
  _database = database;
}

std::vector<Modalidade> DataModalidade::buscaListaModalidade()
{
  // Retorno mockado
  return {
      Modalidade(1, "Judô"),
      Modalidade(2, "Karatê"),
  };
}
