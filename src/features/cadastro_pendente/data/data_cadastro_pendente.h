#ifndef INF112_DATA_CADASTRO_PENDENTE_H
#define INF112_DATA_CADASTRO_PENDENTE_H
#include <libpq-fe.h>
#include <vector>
#include "cad_pendente.h"

class DataCadastroPendente
{
private:
  PGconn *_conn;

public:
  DataCadastroPendente(PGconn *conn);
  std::vector<CadPendente *> buscaListaCadastroPendente();
};

#endif