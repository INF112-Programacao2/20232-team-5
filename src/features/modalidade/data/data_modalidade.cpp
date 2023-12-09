#include "data_modalidade.h"
#include "modalidade.h"
#include <libpq-fe.h>

DataModalidade::DataModalidade(Database *database)
{
  _database = database;
}

//cadastra modalidade
void DataModalidade::cadastraModalidade(Modalidade *modalidade)
{
  std::string query = "INSERT INTO public.\"MODALIDADE\" "
                      "(\"CHAVEMOD\", \"NOME\") "
                      "VALUES ($1, $2)";

  std::vector<std::string> params = {
      std::to_string(modalidade->getChaveMod()),
      modalidade->getNome(),
  };

  try
  {
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



// Recupera a lista de modalidades cadastradas
std::vector<Modalidade> DataModalidade::buscaListaModalidade()
{
  std::string query = "SELECT * FROM \"MODALIDADE\"";
  PGresult *res = _database->executar(query);
  std::vector<Modalidade> listaModalidade;

  for (int i = 0; i < PQntuples(res); i++)
    listaModalidade.push_back(Modalidade::fromDatabase(res, i));

  PQclear(res);
  return listaModalidade;
}

//editar modalidade
void DataModalidade::editaModalidade(Modalidade *modalidade)
{
  std::string query = "UPDATE public.\"MODALIDADE\" "
                      "SET \"NOME\"=$1 "
                      "WHERE \"CHAVEMOD\"=$2";

  std::vector<std::string> params = {
      modalidade->getNome(),
      std::to_string(modalidade->getChaveMod()),
  };

  try
  {
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

//excluir modalidade
void DataModalidade::excluiModalidade(Modalidade *modalidade)
{
  std::string query = "DELETE FROM public.\"MODALIDADE\" "
                      "WHERE \"CHAVEMOD\"=$1";

  std::vector<std::string> params = {
      std::to_string(modalidade->getChaveMod()),
  };

  try
  {
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
