#include "data_modalidade.h"
#include "modalidade.h"
#include <libpq-fe.h>

DataModalidade::DataModalidade(Database *database)
{
  _database = database;
}

// Recupera a lista de modalidades cadastradas
std::vector<Modalidade> DataModalidade::buscaListaModalidade()
{
  std::string query = "SELECT * FROM \"MODALIDADE\"";
  PGresult *res = _database->executar(query);
  std::vector<Modalidade> listaModalidade;
  for (int i = 0; i < PQntuples(res); i++)
    listaModalidade.push_back(Modalidade::fromDatabase(res, i));
  PQclear(res);
  return listaModalidade;
}
