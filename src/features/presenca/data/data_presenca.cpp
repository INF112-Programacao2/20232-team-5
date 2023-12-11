#include "data_presenca.h"

DataPresenca::DataPresenca(Database *database)
    : _database(database)
{
}

void DataPresenca::RegistrarPresenca(int chaveTur, int chaveUsu)
{
    std::string query = "INSERT INTO \"PRESENCA\" (\"CHAVETUR\", \"CHAVEUSU\") VALUES ($1, $2)";
    std::vector<std::string> params = {std::to_string(chaveTur), std::to_string(chaveUsu)};
    PGresult *res = _database->executar(query, params);
    PQclear(res);
}