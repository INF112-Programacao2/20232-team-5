#ifndef INF112_DATA_GRADUACAO_H
#define INF112_DATA_GRADUACAO_H
#include <vector>
#include "graduacao.h"
#include "database.h"
#include "data_modalidade.h"

class DataGraduacao
{
private:
  DataModalidade *_dataModalidade;
  Database *_database;

public:
  DataGraduacao(Database *database, DataModalidade *dataModalidade);
  void editarGraduacao(Graduacao *graduacao);
  void excluirGraduacao(Graduacao *graduacao);
  void cadastraGraduacao(Graduacao *graduacao);
  void listarGraduacao();
  Graduacao *buscaGraduacaoInicial(int chaveMod);
  Graduacao *buscaGraduacaoAluno(int chavAlu);
  Graduacao *buscaGraduacao(int chaveGrd);
  std::vector<Graduacao> buscaGraduacoesSeguintes(Graduacao *gradAtual);
};

#endif