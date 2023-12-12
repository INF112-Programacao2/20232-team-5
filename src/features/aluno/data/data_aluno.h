#ifndef INF112_DATA_ALUNO_H
#define INF112_DATA_ALUNO_H
#include <vector>
#include "database.h"
#include "aluno.h"

class DataAluno
{
private:
  Database *_database;

public:
  DataAluno(Database *database);
  void criaAluno(Aluno *aluno);
  std::vector<Aluno> buscaListaAlunos(int chaveMod);
  std::vector<Aluno> buscaListaAlunosAptos(int chaveMod);
  // Busca aluno por chave do aluno e da graduação
  Aluno *buscaAluno(int chaveAlu, int chaveMod);
  void realizaGraduacao(int chaveAlu, int chaveGrd);
};

#endif