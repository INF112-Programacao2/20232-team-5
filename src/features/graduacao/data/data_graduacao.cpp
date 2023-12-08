#include "data_graduacao.h"
#include <libpq-fe.h>
#include <string>

/*Mock:
    Graduacao(
      1,
      1,
      "Faixa Branca",
      1,
      30)
*/

DataGraduacao::DataGraduacao(Database *database)
{
  _database = database;
}

void DataGraduacao::cadastraGraduacao(Graduacao *graduacao)
{
  // Mock
}

Graduacao *DataGraduacao::buscaGraduacaoInicial(int chaveMod)
{
  std::string query = "SELECT * FROM \"GRADUACAO\" WHERE \"CHAVEMOD\" = $1 AND \"ORDEM\" = 1;";
  std::vector<std::string> params = {std::to_string(chaveMod)};
  PGresult *res = _database->executar(query, params);
  Graduacao *g = nullptr;
  if (PQntuples(res))
    g = Graduacao::fromDatabaseToPtr(res, 0);
  PQclear(res);
  return g;
}