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
  std::string query = "INSERT INTO \"MODALIDADE\" "
                      "(\"NOME\") "
                      "VALUES ($1)";

  std::vector<std::string> params = {modalidade->getNome()};

  PGresult *res = _database->executar(query, params);
  PQclear(res);
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
  std::string query = "SELECT m.*FROM \"MODALIDADE\" m INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEMOD\" = m.\"CHAVEMOD\" WHERE m.\"CHAVEMOD\" NOT IN(SELECT m.\"CHAVEMOD\" FROM \"USUARIO\" u INNER JOIN \"ALUNO\" a ON a.\"CHAVEUSU\" = u.\"CHAVEUSU\" INNER JOIN \"GRADUACAO\" g ON g.\"CHAVEGRD\" = a.\"CHAVEGRD\" INNER JOIN \"MODALIDADE\" m ON m.\"CHAVEMOD\" = g.\"CHAVEMOD\" WHERE u.\"CHAVEUSU\" = $1) AND m.\"CHAVEMOD\" NOT IN(SELECT \"CHAVEMOD\" FROM \"CADPENDENTE\" WHERE \"CHAVEUSU\" = $1) GROUP BY m.\"CHAVEMOD\";";

  std::vector<std::string> params = {std::to_string(chaveUsu)};

  PGresult *res = _database->executar(query, params);
  std::vector<Modalidade> listaModalidade;

  for (int i = 0; i < PQntuples(res); i++)
    listaModalidade.push_back(Modalidade::fromDatabase(res, i));

  PQclear(res);
  return listaModalidade;
}

// Busca lista de modalidades cadastradas para um usuário
std::vector<Modalidade *> DataModalidade::buscaListaModalidadesUsuario(int chaveUsu)
{
  std::string query = "SELECT M.\"CHAVEMOD\", M.\"NOME\" "
                      "FROM \"MODALIDADE\" M "
                      "LEFT JOIN \"GRADUACAO\" G ON G.\"CHAVEMOD\" = M.\"CHAVEMOD\" "
                      "LEFT JOIN \"ALUNO\" A ON A.\"CHAVEGRD\" = G.\"CHAVEGRD\" "
                      "WHERE A.\"CHAVEUSU\" = $1";

  std::vector<std::string> params = {std::to_string(chaveUsu)};

  PGresult *res = _database->executar(query, params);
  std::vector<Modalidade *> listaModalidade;

  for (int i = 0; i < PQntuples(res); i++)
    listaModalidade.push_back(Modalidade::fromDatabaseToPtr(res, i));

  PQclear(res);
  return listaModalidade;
}

// editar modalidade
void DataModalidade::editaModalidade(int chaveMod, std::string nome)
{
  std::string query = "UPDATE public.\"MODALIDADE\" "
                      "SET \"NOME\"=$1 "
                      "WHERE \"CHAVEMOD\"=$2";

  std::vector<std::string> params = {
      nome,
      std::to_string(chaveMod),
  };

  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

// excluir as graduações e sua modalidade se não houver alunos
void DataModalidade::excluiModalidade(int chaveMod)
{
  std::string queryCheckAlunos = "SELECT COUNT(*) FROM \"ALUNO\" WHERE \"CHAVEGRD\" IN (SELECT \"CHAVEGRD\" FROM \"GRADUACAO\" WHERE \"CHAVEMOD\" = $1)";
  std::vector<std::string> paramsCheckAlunos = {std::to_string(chaveMod)};

  PGresult *resCheckAlunos = _database->executar(queryCheckAlunos, paramsCheckAlunos);
  int numAlunos = std::stoi(PQgetvalue(resCheckAlunos, 0, 0));
  PQclear(resCheckAlunos);

  if (numAlunos == 0)
  {
    std::string queryDeleteGraduacoes = "DELETE FROM \"GRADUACAO\" WHERE \"CHAVEMOD\" = $1";
    std::vector<std::string> paramsDeleteGraduacoes = {std::to_string(chaveMod)};

    PGresult *resDeleteGraduacoes = _database->executar(queryDeleteGraduacoes, paramsDeleteGraduacoes);
    PQclear(resDeleteGraduacoes);
  }
  else
  {
    std::cerr << "Não foi possível excluir a modalidade, pois existem alunos matriculados nela!" << std::endl;
    return;
  }

  std::string queryDeleteModalidade = "DELETE FROM \"MODALIDADE\" WHERE \"CHAVEMOD\" = $1";
  std::vector<std::string> paramsDeleteModalidade = {std::to_string(chaveMod)};

  PGresult *resDeleteModalidade = _database->executar(queryDeleteModalidade, paramsDeleteModalidade);
  PQclear(resDeleteModalidade);
}

// Busca modalidade pela chave
Modalidade *DataModalidade::buscaModalidade(int chaveMod)
{
  std::string query = "SELECT * FROM \"MODALIDADE\" WHERE \"CHAVEMOD\" = $1;";
  std::vector<std::string> params = {std::to_string(chaveMod)};

  PGresult *res = _database->executar(query, params);
  Modalidade *modalidade = nullptr;
  if (PQntuples(res))
    modalidade = Modalidade::fromDatabaseToPtr(res, 0);
  PQclear(res);
  return modalidade;
}
