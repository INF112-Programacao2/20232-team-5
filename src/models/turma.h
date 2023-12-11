#ifndef INF112_TURMA_H
#define INF112_TURMA_H

#include <string>
#include <vector>
#include <libpq-fe.h>

class Turma
{
private:
  int _chaveTur;
  int _chaveUsu;
  int _chaveMod;
  std::string _hrInicio;
  std::string _hrFim;
  std::string _diasSemana;

  int HoraEmMinutos(std::string hora);

public:
  Turma(int chaveTur, int chaveUsu, int chaveMod, std::string hrInicio, std::string hrFim, std::string diasSemana);

  // Getters
  int getChaveTur();
  int getChaveUsu();
  int getChaveMod();
  std::string getHrInicio();
  // hora inicio em minutos
  int getHrInicioTime();
  std::string getHrFim();
  // hora fim em minutos
  int getHrFimTime();
  std::string getDiasSemana();
  std::vector<int> getListaDiasSemana();

  // Setters
  void setChaveTur(int chaveTur);
  void setChaveUsu(int chaveUsu);
  void setChaveMod(int chaveMod);
  void setHrInicio(std::string hrInicio);
  void setHrFim(std::string hrFim);
  void setDiasSemana(std::string diasSemana);

  // Métodos
  static Turma *fromDatabase(PGresult *res, int row);
};

#endif