#ifndef INF112_DATA_MODALIDADE_H
#define INF112_DATA_MODALIDADE_H
#include "database.h"
#include <vector>
#include "modalidade.h"

class DataModalidade
{
private:
  Database *_database;

public:
  DataModalidade(Database *database);
  std::vector<Modalidade> buscaListaModalidade();
};

#endif