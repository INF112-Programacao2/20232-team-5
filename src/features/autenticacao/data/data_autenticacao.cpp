#include "data_autenticacao.h"
#include <libpq-fe.h>
#include <string>
#include <iostream>
#include <vector>

DataAutenticacao::DataAutenticacao(Database *database)
{
  _database = database;
}

// Realiza o cadastro de um novo cadPendente (usuário externo)
void DataAutenticacao::inscreveCadastroPendente(CadPendente *cad)
{
  std::string query = "INSERT INTO public.\"CADPENDENTE\" (\"NOME\", \"APELIDO\", \"DTNASCIMENTO\", \"CPF\", \"RG\", \"SEXO\", \"LOGIN\", \"SENHA\", \"TIPO\", \"CHAVEMOD\", \"CHAVEUSU\", \"TIPOCADASTRO\") VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12)";
  std::vector<std::string> params = {
      cad->getNome(),
      cad->getApelido(),
      cad->getDtNascimento(),
      cad->getCpf(),
      cad->getRg(),
      cad->getSexo() ? std::string(1, cad->getSexo()) : "NULL",
      cad->getLogin(),
      cad->getSenha(),
      cad->getTipo() ? std::string(1, cad->getTipo()) : "NULL",
      cad->getChaveMod() ? std::to_string(cad->getChaveMod()) : "NULL",
      cad->getChaveUsu() ? std::to_string(cad->getChaveUsu()) : "NULL",
      cad->getTipoCadastro() ? std::string(1, cad->getTipoCadastro()) : "NULL",
  };

  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

// Busca um usuário específico
Usuario *DataAutenticacao::buscaUsuario(std::string login)
{
  std::string query = "SELECT * FROM \"USUARIO\" WHERE \"LOGIN\" = $1";
  std::vector<std::string> params = {
      login,
  };
  PGresult *res = _database->executar(query, params);
  Usuario *u = nullptr;
  if (PQntuples(res))
    u = Usuario::fromDatabase(res, 0);
  PQclear(res);
  return u;
}

// Busca pelos perfis do usuário
std::vector<Perfil> DataAutenticacao::buscaPerfis(int chaveUsu)
{
  std::string query = "SELECT * FROM \"PERFIL\" WHERE \"CHAVEUSU\" = $1";
  std::vector<std::string> params = {
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  std::vector<Perfil> listaPerfil;
  for (int i = 0; i < PQntuples(res); i++)
    listaPerfil.push_back(Perfil::fromDatabase(res, i));
  PQclear(res);
  return listaPerfil;
}

// Verifica se login já está cadastrado no banco
bool DataAutenticacao::existeLogin(std::string login)
{
  std::string query = "SELECT * FROM \"USUARIO\" WHERE \"LOGIN\" = $1";
  std::vector<std::string> params = {
      login,
  };
  PGresult *res = _database->executar(query, params);
  bool result = PQntuples(res);
  PQclear(res);
  return result;
}