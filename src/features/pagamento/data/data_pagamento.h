#ifndef INF112_DATA_PAGAMENTO_H
#define INF112_DATA_PAGAMENTO_H
#include "enums.h"
#include "database.h"

class DataPagamento
{
private:
  Database *_database;

public:
  DataPagamento(Database *database);
  // Cria a mensalidade de certo usuário
  void criaMensalidade(int chaveUsu, double valor);
  // Edita a mensalidade de certo usuário
  void editaMensalidade(int chaveUsu, double valor);
  // Checa se certo usuário já possui mensalidade cadastrada
  bool checaExisteMensalidade(int chaveUsu);
  // Busca o valor da mensalidade de certo usuário
  double buscaValorMensalidade(int chaveUsu);
};

#endif