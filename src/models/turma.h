#ifndef INF112_TURMA_H
#define INF112_TURMA_H

#include <string>

class Turma
{
private:
  int _chaveTur;
  int _chavePes;
  int _chaveMod;
  std::string _hrInicio;
  std::string _hrFim;
  std::string _diasSemana;

public:
  Turma(int chaveTur, int chavePes, int chaveMod, std::string hrInicio, std::string hrFim, std::string diasSemana);

  // Getters
  int getChaveTur();
  int getChavePes();
  int getChaveMod();
  std::string getHrInicio();
  std::string getHrFim();
  std::string getDiasSemana();

  // Setters
  void setChaveTur(int chaveTur);
  void setChavePes(int chavePes);
  void setChaveMod(int chaveMod);
  void setHrInicio(std::string hrInicio);
  void setHrFim(std::string hrFim);
  void setDiasSemana(std::string diasSemana);
};

#endif