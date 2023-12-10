#include "data_perfil.h"

DataPerfil::DataPerfil(Database *database) : _database(database)
{
}

// Busca pelos perfis do usuário
std::vector<TipoPerfil> DataPerfil::buscaPerfis(int chaveUsu)
{
  std::string query = "SELECT * FROM \"PERFIL\" WHERE \"CHAVEUSU\" = $1";
  std::vector<std::string> params = {std::to_string(chaveUsu)};
  PGresult *res = _database->executar(query, params);
  std::vector<TipoPerfil> listaPerfil;
  for (int i = 0; i < PQntuples(res); i++)
    listaPerfil.push_back(
        static_cast<TipoPerfil>(Database::value(res, i, "TIPO")[0]));
  PQclear(res);
  return listaPerfil;
}

// Checa se usuário tem perfil de determinado tipo
bool DataPerfil::checaTemPerfil(int chaveUsu, TipoPerfil tipo)
{
  std::string query = "SELECT * FROM \"PERFIL\" WHERE \"TIPO\" = $1 AND \"CHAVEUSU\" = $2";
  std::vector<std::string> params = {
      std::string(1, tipo),
      std::to_string(chaveUsu)};
  PGresult *res = _database->executar(query, params);
  bool has = PQntuples(res);
  PQclear(res);
  return has;
}

void DataPerfil::criaPerfil(int chaveUsu, char tipo)
{
  std::string query = "INSERT INTO public.\"PERFIL\"(\"CHAVEUSU\", \"TIPO\") VALUES($1, $2);";
  std::vector<std::string> params = {
      std::to_string(chaveUsu),
      std::string(1, tipo)};

  PGresult *res = _database->executar(query, params);
  PQclear(res);
}