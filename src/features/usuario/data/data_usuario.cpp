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
    u = Usuario::fromDatabaseToPtr(res, 0);
  PQclear(res);
  return u;
}

int DataUsuario::criaUsuario(Usuario *usuario)
{
  std::string query = "INSERT INTO public.\"USUARIO\" (\"NOME\", \"APELIDO\", \"DTNASCIMENTO\", \"CPF\", \"SEXO\", \"LOGIN\", \"SENHA\") VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING \"CHAVEUSU\";";
  std::vector<std::string> params = {
      usuario->getNome(),
      usuario->getApelido(),
      usuario->getDtNascimento(),
      usuario->getCpf(),
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
  std::string query = "UPDATE \"USUARIO\" SET \"NOME\" = $1 WHERE \"CHAVEUSU\" = $2;";
  std::vector<std::string> params = {
      nome,
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaApelido(int chaveUsu, std::string apelido)
{
  std::string query = "UPDATE \"USUARIO\" SET \"APELIDO\" = $1 WHERE \"CHAVEUSU\" = $2;";
  std::vector<std::string> params = {
      apelido,
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaDtNascimento(int chaveUsu, std::string dtNascimento)
{
  std::string query = "UPDATE \"USUARIO\" SET \"DTNASCIMENTO\" = $1 WHERE \"CHAVEUSU\" = $2;";
  std::vector<std::string> params = {
      dtNascimento,
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaCpf(int chaveUsu, std::string cpf)
{
  std::string query = "UPDATE \"USUARIO\" SET \"CPF\" = $1 WHERE \"CHAVEUSU\" = $2;";
  std::vector<std::string> params = {
      cpf,
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaSexo(int chaveUsu, char sexo)
{
  std::string query = "UPDATE \"USUARIO\" SET \"SEXO\" = $1 WHERE \"CHAVEUSU\" = $2;";
  std::vector<std::string> params = {
      std::string(1, sexo),
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

void DataUsuario::editaLogin(int chaveUsu, std::string login)
{
  std::string query = "UPDATE \"USUARIO\" SET \"LOGIN\" = $1 WHERE \"CHAVEUSU\" = $2;";
  std::vector<std::string> params = {
      login,
      std::to_string(chaveUsu),
  };
  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

std::vector<Usuario> DataUsuario::buscaListaUsuario()
{
  std::string query = "SELECT * FROM \"USUARIO\"";

  PGresult *res = _database->executar(query);
  std::vector<Usuario> listaUsuario;
  for (int i = 0; i < PQntuples(res); i++)
    listaUsuario.push_back(Usuario::fromDatabase(res, i));
  PQclear(res);
  return listaUsuario;
}
