#ifndef INF112_DATA_GRADUACAO_H
#define INF112_DATA_GRADUACAO_H
#include "graduacao.h"
#include "database.h"

class DataGraduacao
{
private:
  Database *_database;

public:
  DataGraduacao(Database *database);
  void cadastraGraduacao(Graduacao *graduacao);
  Graduacao *buscaGraduacaoInicial(int chaveMod);
};

#endif