#ifndef INF112_DATA_PRESENCA_H
#define INF112_DATA_PRESENCA_H

#include "database.h"
#include <vector>

class DataPresenca
{
private:
  Database *_database;

public:
  DataPresenca(Database *database);
  void RegistrarPresenca(int chaveTur, int chaveUsu);
};

#endif