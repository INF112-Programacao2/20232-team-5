#ifndef INF112_PERFIL_H
#define INF112_PERFIL_H

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
};

#endif