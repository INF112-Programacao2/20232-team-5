#include "data_graduacao.h"
#include <libpq-fe.h>
#include <string>

DataGraduacao::DataGraduacao(Database *database)
{
  _database = database;
}

void DataGraduacao::cadastraGraduacao(Graduacao *graduacao)
{
  // Mock
}

Graduacao DataGraduacao::buscaGraduacaoInicial(int chaveMod)
{
  // std::string query = "SELECT * FROM "
  return Graduacao(
      1,
      1,
      "Faixa Branca",
      1,
      30);
}