#ifndef INF112_DATA_TURMA_H
#define INF112_DATA_TURMA_H
#include <libpq-fe.h>
#include "turma.h"
#include <bits/stdc++.h>

class DataTurma
{
private:
  PGconn *_conn;

public:
  DataTurma(PGconn *conn);
  void cadastraTurma(Turma *turma);
};

#endif