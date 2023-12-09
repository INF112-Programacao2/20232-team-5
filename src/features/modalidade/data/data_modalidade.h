#ifndef INF112_DATA_MODALIDADE_H
#define INF112_DATA_MODALIDADE_H
#include "database.h"
#include <vector>
#include "modalidade.h"

class DataModalidade
{
private:
  Database *_database;

public:
  DataModalidade(Database *database);
  //cadastrar modalidade
  void cadastraModalidade(Modalidade *modalidade);
  std::vector<Modalidade> buscaListaModalidade();
  //editar modalidade
  void editaModalidade(Modalidade *modalidade);
  //excluir modalidade
  void excluiModalidade(Modalidade *modalidade);
};

#endif