#ifndef INF112_DATA_CADASTRO_PENDENTE_H
#define INF112_DATA_CADASTRO_PENDENTE_H
#include <vector>
#include "cad_pendente.h"

class DataCadastroPendente
{
public:
  std::vector<CadPendente *> buscaListaCadastroPendente();
};

#endif