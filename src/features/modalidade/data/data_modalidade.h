#ifndef INF112_DATA_MODALIDADE_H
#define INF112_DATA_MODALIDADE_H
#include <libpq-fe.h>
#include <vector>
#include "modalidade.h"

class DataModalidade
{
private:
  PGconn *_conn;

public:
  DataModalidade(PGconn *conn);
  std::vector<Modalidade> leListaModalidade();
};

#endif