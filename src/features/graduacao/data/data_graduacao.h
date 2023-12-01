#ifndef INF112_DATA_GRADUACAO_H
#define INF112_DATA_GRADUACAO_H
#include <libpq-fe.h>
#include "graduacao.h"

class DataGraduacao
{
private:
  PGconn *_conn;

public:
  DataGraduacao(PGconn *conn);
  void cadastraGraduacao(Graduacao *graduacao);
};

#endif