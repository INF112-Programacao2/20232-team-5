#ifndef INF112_DATA_GRADUACAO_H
#define INF112_DATA_GRADUACAO_H
#include <vector>
#include "graduacao.h"
#include "database.h"

class DataGraduacao
{
private:
  Database *_database;

public:
  DataGraduacao(Database *database);
  void editarGraduacao(Graduacao *graduacao);
  void excluirGraduacao(Graduacao *graduacao);
  void cadastraGraduacao(Graduacao *graduacao);
  void listarGraduacao();
  Graduacao *buscaGraduacaoInicial(int chaveMod);
  Graduacao *buscaGraduacaoAluno(int chavAlu);
  std::vector<Graduacao> buscaGraduacoesSeguintes(Graduacao *gradAtual);
};

#endif