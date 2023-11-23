#ifndef INF112_MODALIDADE_H
#define INF112_MODALIDADE_H

#include <string>

class Modalidade
{
private:
  int _chaveMod;
  std::string _nome;

public:
  Modalidade(int chaveMod, std::string nome);

  // Getters
  int getChaveMod();
  std::string getNome();

  // Setters
  void setChaveMod(int chaveMod);
  void setNome(std::string nome);
};

#endif