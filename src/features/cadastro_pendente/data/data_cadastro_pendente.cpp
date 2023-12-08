#include "data_cadastro_pendente.h"
#include <libpq-fe.h>
#include <iostream>
#include <vector>
#include "cad_pendente.h"

DataCadastroPendente::DataCadastroPendente(Database *database)
{
    _database = database;
}

std::vector<CadPendente> DataCadastroPendente::buscaListaCadastroPendente()
{
    std::string SQL = "SELECT * FROM \"CADPENDENTE\"";

    PGresult *query = _database->executar(SQL);
    std::vector<CadPendente> listaCadPendente;

    for (int i = 0; i < PQntuples(query); i++)
        listaCadPendente.push_back(CadPendente::fromDatabase(query, i));

    PQclear(query);
    return listaCadPendente;
}

CadPendente *DataCadastroPendente::buscaByChave(int chaveCad)
{
    std::string query = "SELECT * FROM \"CADPENDENTE\" WHERE \"CHAVECAD\" = $1";
    std::vector<std::string> params = {std::to_string(chaveCad)};
    PGresult *res = _database->executar(query, params);
    CadPendente *c = nullptr;
    if (PQntuples(res))
        c = CadPendente::fromDatabaseToPtr(res, 0);
    PQclear(res);
    return c;
}

void DataCadastroPendente::deletaCadastro(int chaveCad)
{
    std::string query = "DELETE FROM \"CADPENDENTE\" WHERE \"CHAVECAD\" = $1";
    std::vector<std::string> params = {std::to_string(chaveCad)};
    PGresult *res = _database->executar(query, params);
    PQclear(res);
}

void DataCadastroPendente::criaPerfil(int chaveUsu, char tipo)
{
    // Mock
}