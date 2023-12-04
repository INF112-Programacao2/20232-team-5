#include "data_graduacao.h"

DataGraduacao::DataGraduacao(PGconn *conn)
{
  _conn = conn;
}

void DataGraduacao::cadastraGraduacao(Graduacao *graduacao)
{
  // Mock
}