﻿#include "data_graduacao.h"
#include <libpq-fe.h>
#include <bits/stdc++.h>

/*Mock:
    Graduacao(
      1,
      1,
      "Faixa Branca",
      1,
      30)
*/

DataGraduacao::DataGraduacao(Database *database)
{
  _database = database;
}

void DataGraduacao::cadastraGraduacao(Graduacao *graduacao)
{
  std::string insertQuery = "INSERT INTO \"GRADUACAO\" (\"CHAVEMOD\", \"NOME\", \"ORDEM\", \"MINAULAS\") VALUES ($1, $2, $3, $4)";

  std::vector<std::string> params = {
      std::to_string(graduacao->getChaveMod()),
      graduacao->getNome(),
      std::to_string(graduacao->getOrdem()),
      std::to_string(graduacao->getMinAulas()),
  };

  try
  {
    PGresult *res = _database->executar(insertQuery, params);
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

Graduacao *DataGraduacao::buscaGraduacaoInicial(int chaveMod)
{
  std::string query = "SELECT * FROM \"GRADUACAO\" WHERE \"CHAVEMOD\" = $1 AND \"ORDEM\" = 1;";
  std::vector<std::string> params = {std::to_string(chaveMod)};
  PGresult *res = _database->executar(query, params);
  Graduacao *g = nullptr;
  if (PQntuples(res))
    g = Graduacao::fromDatabaseToPtr(res, 0);
  PQclear(res);
  return g;
}

// editar uma graduação: Modificar nome, ordem ou nº de dias para graduação
void DataGraduacao::editarGraduacao(Graduacao *graduacao)
{
  std::string updateQuery = "UPDATE \"GRADUACAO\" SET \"NOME\" = $1, \"ORDEM\" = $2, \"MINAULAS\" = $3 WHERE \"CHAVEGRD\" = $4";

  std::vector<std::string> params = {
      graduacao->getNome(),
      std::to_string(graduacao->getOrdem()),
      std::to_string(graduacao->getMinAulas()),
      std::to_string(graduacao->getChaveGrd()),
  };

  try
  {
    PGresult *res = _database->executar(updateQuery, params);
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

// excluir uma graduação: Não é possível caso já haja ao menos 1 aluno com a graduação.
void DataGraduacao::excluirGraduacao(Graduacao *graduacao)
{
  std::string checkAlunoQuery = "SELECT COUNT(*) FROM \"ALUNO\" WHERE \"CHAVEGRD\" = $1";
  std::vector<std::string> checkAlunoParams = {
      std::to_string(graduacao->getChaveGrd()),
  };

  PGresult *checkAlunoRes = _database->executar(checkAlunoQuery, checkAlunoParams);
  int numAlunos = std::stoi(PQgetvalue(checkAlunoRes, 0, 0));
  PQclear(checkAlunoRes);

  if (numAlunos > 0)
  {
    std::cerr << "Não é possível excluir a graduação pois existem " << numAlunos << " aluno(s) cadastrado(s)!" << std::endl;
    return;
  }

  std::string deleteQuery = "DELETE FROM \"GRADUACAO\" WHERE \"CHAVEGRD\" = $1";

  std::vector<std::string> deleteParams = {
      std::to_string(graduacao->getChaveGrd()),
  };

  try
  {
    PGresult *res = _database->executar(deleteQuery, deleteParams);
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

// listar as graduações cadastradas no sistema, por modalidade
void DataGraduacao::listarGraduacao()
{
  std::string query = "SELECT * FROM \"GRADUACAO\" ORDER BY \"CHAVEMOD\", \"ORDEM\";";
  PGresult *res = _database->executar(query);
  int n = PQntuples(res);
  if (n == 0)
  {
    std::cout << "Não há graduações cadastradas!" << std::endl;
    return;
  }
  std::cout << std::setw(10) << "CHAVEGRD"
            << " | " << std::setw(10) << "CHAVEMOD"
            << " | "
            << std::setw(20) << "NOME"
            << " | " << std::setw(10) << "ORDEM"
            << " | " << std::setw(10) << "MINAULAS" << std::endl;

  for (int i = 0; i < n; i++)
  {
    Graduacao *g = Graduacao::fromDatabaseToPtr(res, i);
    std::cout << std::setw(10) << g->getChaveGrd() << " | " << std::setw(10) << g->getChaveMod() << " | "
              << std::setw(20) << g->getNome() << " | " << std::setw(10) << g->getOrdem() << " | " << std::setw(10) << g->getMinAulas() << std::endl;
  }
  PQclear(res);
}

Graduacao *DataGraduacao::buscaGraduacaoAluno(int chaveAlu)
{
  std::string query = "SELECT * FROM \"GRADUACAO\" g INNER JOIN \"ALUNO\" a ON a.\"CHAVEGRD\" = g.\"CHAVEGRD\" WHERE \"CHAVEALU\" = $1;";
  std::vector<std::string> params = {std::to_string(chaveAlu)};
  PGresult *res = _database->executar(query, params);
  Graduacao *g = nullptr;
  if (PQntuples(res))
    g = Graduacao::fromDatabaseToPtr(res, 0);
  PQclear(res);
  return g;
}

std::vector<Graduacao> DataGraduacao::buscaGraduacoesSeguintes(Graduacao *gradAtual)
{
  std::string query = "SELECT * FROM \"GRADUACAO\" WHERE \"CHAVEMOD\" = $1 AND \"ORDEM\" > $2 ORDER BY \"ORDEM\";";
  std::vector<std::string> params = {
      std::to_string(gradAtual->getChaveMod()),
      std::to_string(gradAtual->getOrdem()),
  };
  PGresult *res = _database->executar(query, params);
  std::vector<Graduacao> listaGraduacao;
  for (int i = 0; i < PQntuples(res); i++)
    listaGraduacao.push_back(Graduacao::fromDatabase(res, i));
  PQclear(res);
  return listaGraduacao;
}
