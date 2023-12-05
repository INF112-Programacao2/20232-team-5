#ifndef INF112_PERFIL_H
#define INF112_PERFIL_H
#include <libpq-fe.h>

class Perfil
{
private:
  int _chavePer;
  char _tipo;

public:
  Perfil(int chavePer, char tipo);

  int getChavePer();
  char getTipo();

  void setChavePer(int chavePer);
  void setTipo(char tipo);

  // Conversion
  static Perfil fromDatabase(PGresult *res, int row);
};

#endif