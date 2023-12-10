#include "data_pagamento.h"

DataPagamento::DataPagamento(Database *database) : _database(database) {}

// Cria a mensalidade de certo usuário
void DataPagamento::criaMensalidade(int chaveUsu, double valor)
{
  std::string query = "INSERT INTO \"MENSALIDADE\"(\"CHAVEUSU\", \"VALOR\") VALUES($1, $2);";
  std::vector<std::string> params = {
      std::to_string(chaveUsu),
      std::to_string(valor),
  };

  PGresult *res = _database->executar(query, params);
  PQclear(res);
}
// Edita a mensalidade de certo usuário
void DataPagamento::editaMensalidade(int chaveUsu, double valor)
{
  std::string query = "UPDATE \"MENSALIDADE\" SET \"VALOR\" = $1 WHERE \"CHAVEUSU\" = $2;";
  std::vector<std::string> params = {
      std::to_string(valor),
      std::to_string(chaveUsu),
  };

  PGresult *res = _database->executar(query, params);
  PQclear(res);
}

// Checa se certo usuário já possui mensalidade cadastrada
bool DataPagamento::checaExisteMensalidade(int chaveUsu)
{
  std::string query = "SELECT * FROM \"MENSALIDADE\" WHERE \"CHAVEUSU\" = $1;";
  std::vector<std::string> params = {std::to_string(chaveUsu)};

  PGresult *res = _database->executar(query, params);
  bool existe = PQntuples(res);
  PQclear(res);
  return existe;
}

// Busca a mensalidade de certo usuário
double DataPagamento::buscaValorMensalidade(int chaveUsu)
{
  std::string query = "SELECT \"VALOR\" FROM \"MENSALIDADE\" WHERE \"CHAVEUSU\" = $1;";
  std::vector<std::string> params = {std::to_string(chaveUsu)};

  PGresult *res = _database->executar(query, params);
  double valor = std::stod(Database::value(res, 0, "VALOR"));
  PQclear(res);
  return valor;
}