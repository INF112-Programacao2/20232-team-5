#include "data_presenca.h"

DataPresenca::DataPresenca(Database *database)
    : _database(database)
{
}

void DataPresenca::RegistrarPresenca(int chaveTur, int chaveUsu)
{
    std::string query = "INSERT INTO public.\"PRESENCA\"(\"CHAVEALU\", \"CHAVETUR\") "
                        "VALUES ((select A.\"CHAVEALU\" "
                                 "from \"VALUNO\" A "
                                 "left join \"TURMA\" on \"CHAVETUR\" = $1 "
                                 "where A.\"CHAVEUSU\" = $2), $3)";
                                 
    std::vector<std::string> params = {std::to_string(chaveTur), std::to_string(chaveUsu), std::to_string(chaveTur)};

    try{
        PGresult *res = _database->executar(query, params);
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