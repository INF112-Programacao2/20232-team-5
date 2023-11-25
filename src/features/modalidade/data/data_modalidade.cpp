#include "data_modalidade.h"

std::vector<Modalidade> DataModalidade::leListaModalidade()
{
  // Retorno mockado
  return {
      Modalidade(1, "Judô"),
      Modalidade(2, "Karatê"),
  };
}