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