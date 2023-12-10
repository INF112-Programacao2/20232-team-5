#include "data_modalidade.h"
#include "modalidade.h"
#include <libpq-fe.h>

DataModalidade::DataModalidade(Database *database)
{
  _database = database;
}

// cadastra modalidade
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

// Busca lista de modalidades disponíveis (não cadastradas) para um usuário
std::vector<Modalidade> DataModalidade::buscaListaModalidadesDisponiveis(int chaveUsu)
{
  std::string query = "SELECT * FROM \"MODALIDADE\" m INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEMOD\" = m.\"CHAVEMOD\" WHERE m.\"CHAVEMOD\" NOT IN (SELECT m.\"CHAVEMOD\" FROM \"USUARIO\" u INNER JOIN \"ALUNO\" a ON a.\"CHAVEUSU\" = U.\"CHAVEUSU\" INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEGRD\" = a.\"CHAVEGRD\" INNER JOIN \"MODALIDADE\" m ON m.\"CHAVEMOD\" = g.\"CHAVEMOD\" WHERE u.\"CHAVEUSU\" = $1) AND m.\"CHAVEMOD\" NOT IN (SELECT \"CHAVEMOD\" FROM \"CADPENDENTE\" WHERE \"CHAVEUSU\" = $1);";

  std::vector<std::string> params = {std::to_string(chaveUsu)};

  PGresult *res = _database->executar(query, params);
  std::vector<Modalidade> listaModalidade;

  for (int i = 0; i < PQntuples(res); i++)
    listaModalidade.push_back(Modalidade::fromDatabase(res, i));

  PQclear(res);
  return listaModalidade;
}

// editar modalidade
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

// excluir as graduações e sua modalidade se não houver alunos
void DataModalidade::excluiModalidade(Modalidade *modalidade)
{
  std::string queryCheckAlunos = "SELECT COUNT(*) FROM \"ALUNO\" WHERE \"CHAVEGRD\" IN (SELECT \"CHAVEGRD\" FROM \"GRADUACAO\" WHERE \"CHAVEMOD\" = $1)";
  std::vector<std::string> paramsCheckAlunos = {std::to_string(modalidade->getChaveMod())};

  PGresult *resCheckAlunos = _database->executar(queryCheckAlunos, paramsCheckAlunos);
  int numAlunos = std::stoi(PQgetvalue(resCheckAlunos, 0, 0));
  PQclear(resCheckAlunos);

  if (numAlunos == 0)
  {
    std::string queryDeleteGraduacoes = "DELETE FROM \"GRADUACAO\" WHERE \"CHAVEMOD\" = $1";
    std::vector<std::string> paramsDeleteGraduacoes = {std::to_string(modalidade->getChaveMod())};

    try
    {
      PGresult *resDeleteGraduacoes = _database->executar(queryDeleteGraduacoes, paramsDeleteGraduacoes);
      PQclear(resDeleteGraduacoes);
    }
    catch (DatabaseError e)
    {
      std::cerr << e.what() << std::endl;
      return;
    }
    catch (std::exception e)
    {
      std::cerr << "Ocorreu um erro inesperado!" << std::endl;
      std::cerr << e.what() << std::endl;
      return;
    }
  }else{
    std::cerr << "Não foi possível excluir a modalidade, pois existem alunos matriculados nela!" << std::endl;
    return;
  }

  std::string queryDeleteModalidade = "DELETE FROM \"MODALIDADE\" WHERE \"CHAVEMOD\" = $1";
  std::vector<std::string> paramsDeleteModalidade = {std::to_string(modalidade->getChaveMod())};

  try
  {
    PGresult *resDeleteModalidade = _database->executar(queryDeleteModalidade, paramsDeleteModalidade);
    PQclear(resDeleteModalidade);
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

