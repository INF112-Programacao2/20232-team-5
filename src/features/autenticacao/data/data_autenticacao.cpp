#include "data_autenticacao.h"
#include <libpq-fe.h>
#include <string>
#include <iostream>

DataAutenticacao::DataAutenticacao(PGconn *conn)
{
  _conn = conn;
}

void DataAutenticacao::inscreveCadastroPendente(CadPendente *cad)
{
  // const char *const paramValues[13] = {
  //     std::to_string(cad->getChaveCad()).c_str(),
  //     cad->getNome().c_str(),
  //     cad->getApelido().c_str(),
  //     cad->getDtNascimento().c_str(),
  //     cad->getCpf().c_str(),
  //     cad->getRg().c_str(),
  //     std::to_string(cad->getSexo()).c_str(),
  //     cad->getLogin().c_str(),
  //     cad->getSenha().c_str(),
  //     std::to_string(cad->getTipo()).c_str(),
  //     std::to_string(cad->getChaveMod()).c_str(),
  //     std::to_string(cad->getChaveUsu()).c_str(),
  //     std::to_string(cad->getTipoCadastro()).c_str(),
  // };
  // // cad->toQueryParams(paramValues);
  // //  Execute a query
  // std::string query = "INSERT INTO CADPENDENTE(CHAVECAD, NOME, APELIDO, DTNASCIMENTO, CPF, RG, SEXO, LOGIN, SENHA, TIPO, CHAVEMOD, CHAVEUSU, TIPOCADASTRO) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13)";

  // char query2[1000];
  // sprintf(
  //     query2,
  //     "INSERT INTO public.CADPENDENTE (NOME, APELIDO, DTNASCIMENTO, CPF, RG, SEXO, LOGIN, SENHA, TIPO, CHAVEMOD, CHAVEUSU, TIPOCADASTRO) VALUES (\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \'%c\', \"%s\", \"%s\", \'%c\', %d, %d \'%c\')",
  //     cad->getNome(),
  //     cad->getApelido(),
  //     cad->getDtNascimento(),
  //     cad->getCpf(),
  //     cad->getRg(),
  //     cad->getSexo(),
  //     cad->getLogin(),
  //     cad->getSenha(),
  //     cad->getTipo(),
  //     cad->getChaveMod(),
  //     cad->getChaveUsu(),
  //     cad->getTipoCadastro());

  // PGresult *res = PQexec(_conn, query2);
  // PQescape if (PQresultStatus(res) != PGRES_COMMAND_OK)
  // {
  //   std::cout << "PQexecParams failed: " << PQresultErrorMessage(res)
  //             << std::endl;
  //   std::cout << PQresultStatus(res) << std::endl;
  // }

  const char *insertQuery = "INSERT INTO public.\"CADPENDENTE\" "
                            "(\"NOME\", \"APELIDO\", \"DTNASCIMENTO\", \"CPF\", \"RG\", \"SEXO\", \"LOGIN\", \"SENHA\", \"TIPO\", \"CHAVEMOD\", \"CHAVEUSU\", \"TIPOCADASTRO\") "
                            "VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12)";

  // Set the parameter values directly in the query string
  const char *paramValues[12] = {
      cad->getNome().c_str(),
      cad->getApelido().c_str(),
      cad->getDtNascimento().c_str(),
      cad->getCpf().c_str(),
      cad->getRg().c_str(),
      std::to_string(cad->getSexo()).c_str(),
      cad->getLogin().c_str(),
      cad->getSenha().c_str(),
      std::to_string(cad->getTipo()).c_str(),
      cad->getChaveMod() ? std::to_string(cad->getChaveMod()).c_str() : NULL,
      cad->getChaveUsu() ? std::to_string(cad->getChaveUsu()).c_str() : NULL,
      std::to_string(static_cast<char>(cad->getTipoCadastro())).c_str()};

  // Execute the query
  PGresult *res = PQexecParams(_conn, insertQuery, 12, NULL, paramValues, NULL, NULL, 0);

  // Check for errors in executing the statement
  if (PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    std::cerr << "Error executing SQL statement: " << PQresultErrorMessage(res) << std::endl;
    std::cerr << "Status: " << PQresultStatus(res) << std::endl;
  }

  // Clear the result after executing the statement
  PQclear(res);
}

Usuario *DataAutenticacao::buscaUsuario(std::string login)
{
  std::cout << PQerrorMessage(_conn) << std::endl;
  std::string insertQuery = "SELECT * FROM \"CADPENDENTE\"";
  PGresult *res = PQexec(_conn, insertQuery.c_str());

  // Check for errors in executing the statement
  if (PQresultStatus(res) != PGRES_COMMAND_OK && PQresultStatus(res) != PGRES_TUPLES_OK)
  {
    std::cerr << "Error executing SQL statement: " << PQresultErrorMessage(res) << std::endl;
    std::cerr << PQresultVerboseErrorMessage(res, PGVerbosity::PQERRORS_VERBOSE, PGContextVisibility::PQSHOW_CONTEXT_ALWAYS);
    std::cerr
        << "Status: " << PQresultStatus(res) << std::endl;
  }
  std::cout << PQntuples(res) << std::endl;
  // return nullptr;
  Usuario *u = new Usuario(1, "João", "Joaozin", "17/04/2003", "10164444602", "20834320", 'M', "joaovitor", "senha123");
  return u;
}

std::vector<Perfil> DataAutenticacao::buscaPerfis(int chaveUsu)
{
  // Mock
  return {
      Perfil(1, 'A'),
      // Perfil(2, 'C'),
  };
}

bool DataAutenticacao::existeLogin(std::string login)
{
  // Mock
  return false;
  // return true;
}