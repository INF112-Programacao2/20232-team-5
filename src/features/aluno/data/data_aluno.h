#ifndef INF112_DATA_ALUNO_H
#define INF112_DATA_ALUNO_H
#include "database.h"
#include "aluno.h"

class DataAluno
{
private:
  Database *_database;

public:
  DataAluno(Database *database);
  void criaAluno(Aluno *aluno);
};

#endif