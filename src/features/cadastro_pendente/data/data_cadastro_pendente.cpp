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
    std::string query = "SELECT * FROM \"CADPENDENTE\"";
    PGresult *res = _database->executar(query);
    std::vector<CadPendente> listaCadPendente;
    for (int i = 0; i < PQntuples(res); i++)
    {
        std::cout << PQgetvalue(res, i, 1) << std::endl;
        listaCadPendente.push_back(CadPendente::fromDatabase(res, i));
    }
    PQclear(res);
    return listaCadPendente;
}