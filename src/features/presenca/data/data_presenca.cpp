#include "data_presenca.h"

DataPresenca::DataPresenca(Database *database)
    : _database(database)
{
}

void DataPresenca::RegistrarPresenca(int chaveTur, int chaveAlu)
{
    std::string query = "INSERT INTO public.\"PRESENCA\"(\"CHAVEALU\", \"CHAVETUR\") "
                        "VALUES ($1, $2)";
                                 
    std::vector<std::string> params = {std::to_string(chaveAlu), std::to_string(chaveTur)};

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