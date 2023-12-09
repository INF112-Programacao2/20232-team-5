#include "data_usuario.h"
#include <string>
#include <libpq-fe.h>
#include "global.h"

DataUsuario::DataUsuario(Database *database)
{
  _database = database;
}

void DataUsuario::salvarSenha(int chaveUsu, std::string senha)
{
  std::string query = "UPDATE \"USUARIO\" SET \"SENHA\" = $1;";
  std::vector<std::string> params = {
      senha,
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

Usuario *DataUsuario::buscaUsuarioByChave(int chaveUsu)
{
  std::string query = "SELECT * FROM \"USUARIO\" WHERE \"CHAVEUSU\" = $1";
  std::vector<std::string> params = {
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  Usuario *u = nullptr;
  if (PQntuples(res))
    u = Usuario::fromDatabase(res, 0);
  PQclear(res);
  return u;
}

int DataUsuario::criaUsuario(Usuario *usuario)
{
  std::string query = "INSERT INTO public.\"USUARIO\" (\"NOME\", \"APELIDO\", \"DTNASCIMENTO\", \"CPF\", \"RG\", \"SEXO\", \"LOGIN\", \"SENHA\") VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING \"CHAVEUSU\";";
  std::vector<std::string> params = {
      usuario->getNome(),
      usuario->getApelido(),
      usuario->getDtNascimento(),
      usuario->getCpf(),
      usuario->getRg(),
      usuario->getSexo() != nullchar ? std::string(1, usuario->getSexo()) : nullstr,
      usuario->getLogin(),
      usuario->getSenha()};

  PGresult *res = _database->executar(query, params);
  int chaveUsu = std::stoi(Database::value(res, 0, "CHAVEUSU"));
  PQclear(res);
  return chaveUsu;
}

void DataUsuario::editaNome(int chaveUsu, std::string nome)
{
  std::string query = "UPDATE \"USUARIO\" SET \"NOME\" = $1;";
  std::vector<std::string> params = {
      nome,
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaApelido(int chaveUsu, std::string apelido)
{
  std::string query = "UPDATE \"USUARIO\" SET \"APELIDO\" = $1;";
  std::vector<std::string> params = {
      apelido,
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaDtNascimento(int chaveUsu, std::string dtNascimento)
{
  std::string query = "UPDATE \"USUARIO\" SET \"DTNASCIMENTO\" = $1;";
  std::vector<std::string> params = {
      dtNascimento,
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaCpf(int chaveUsu, std::string cpf)
{
  std::string query = "UPDATE \"USUARIO\" SET \"CPF\" = $1;";
  std::vector<std::string> params = {
      cpf,
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaSexo(int chaveUsu, char sexo)
{
  std::string query = "UPDATE \"USUARIO\" SET \"SEXO\" = $1;";
  std::vector<std::string> params = {
      std::string(1, sexo),
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaLogin(int chaveUsu, std::string login)
{
  std::string query = "UPDATE \"USUARIO\" SET \"LOGIN\" = $1;";
  std::vector<std::string> params = {
      login,
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}
