#ifndef INF112_DATA_PERFIL_H
#define INF112_DATA_PERFIL_H
#include "enums.h"
#include "database.h"

class DataPerfil
{
private:
  Database *_database;

public:
  DataPerfil(Database *database);
  std::vector<TipoPerfil> buscaPerfis(int chaveUsu);
  bool checaTemPerfil(int chaveUsu, TipoPerfil tipo);
  void criaPerfil(int chaveUsu, TipoPerfil tipo);
  void removePerfil(int chaveUsu, TipoPerfil tipo);
};

#endif