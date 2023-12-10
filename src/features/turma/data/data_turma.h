#ifndef INF112_DATA_TURMA_H
#define INF112_DATA_TURMA_H
#include "database.h"
#include "turma.h"
#include <bits/stdc++.h>

class DataTurma
{
private:
  Database *_database;

public:
  DataTurma(Database *database);
  void cadastraTurma(Turma *turma);
  void editarTurma(Turma *turma);
  void excluirTurma(int chaveTurma);
  void listarTurmas();
  void presencaTurma(int chaveTurma);
};

#endif