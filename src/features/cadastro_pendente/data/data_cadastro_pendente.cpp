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
    {
        //std::cout << PQgetvalue(res, i, 1) << std::endl;
        listaCadPendente.push_back(CadPendente::fromDatabase(query, i));
    }

    PQclear(query);
    return listaCadPendente;
}