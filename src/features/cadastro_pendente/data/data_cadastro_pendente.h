#ifndef INF112_DATA_CADASTRO_PENDENTE_H
#define INF112_DATA_CADASTRO_PENDENTE_H
#include <database.h>
#include <vector>
#include "cad_pendente.h"

class DataCadastroPendente
{
private:
  Database *_database;

public:
  DataCadastroPendente(Database *database);
  std::vector<CadPendente> buscaListaCadastroPendente();
  CadPendente *buscaByChave(int chaveCad);
  void deletaCadastro(int chaveCad);
  void criaPerfil(int chaveUsu, char tipo);
};

#endif