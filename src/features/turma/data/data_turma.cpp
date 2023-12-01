#include "data_turma.h"

DataTurma::DataTurma(PGconn *conn)
{
  _conn = conn;
}

void DataTurma::cadastraTurma(Turma *turma)
{
  // Mock
}
