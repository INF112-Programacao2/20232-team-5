#include "data_cadastro_pendente.h"

std::vector<CadPendente *> DataCadastroPendente::buscaListaCadastroPendente()
{
  // Mock
  return {
      new CadPendente(1, "João", "Joaozin", "17/04/2003", "10164444602", "20834320", 'M', "joaovitor", "senha123", 'C', 1),
      new CadPendente(2, "Lucas", "Joaozin", "17/04/2003", "10164444602", "20834320", 'M', "joaovitor", "senha123", 'P'),
      new CadPendente(3, 1, 'P'),
      new CadPendente(4, 2, 'C', 1),
  };
}