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
  std::string insertQuery = "INSERT INTO \"GRADUACAO\" (\"CHAVEMOD\", \"NOME\", \"ORDEM\", \"MINAULAS\") VALUES ($1, $2, $3, $4)";

  std::vector<std::string> params = {
      std::to_string(graduacao->getChaveMod()),
      graduacao->getNome(),
      std::to_string(graduacao->getOrdem()),
      std::to_string(graduacao->getMinAulas()),
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