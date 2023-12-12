#include "turma.h"

Turma::Turma(int chaveTur, int chaveUsu, int chaveMod, std::string hrInicio, std::string hrFim, std::string diasSemana)
    : _chaveTur(chaveTur), _chaveUsu(chaveUsu), _chaveMod(chaveMod),
      _hrInicio(hrInicio), _hrFim(hrFim), _diasSemana(diasSemana)
{
}

int Turma::getChaveTur()
{
  return _chaveTur;
}

int Turma::getChaveUsu()
{
  return _chaveUsu;
}

int Turma::getChaveMod()
{
  return _chaveMod;
}

std::string Turma::getHrInicio()
{
  return _hrInicio;
}

int Turma::HoraEmMinutos(std::string hora)
{
  int horas = std::stoi(hora.substr(0, hora.find(":")));
  int minutos = std::stoi(hora.substr(hora.find(":") + 1));
  return horas * 60 + minutos;
}

int Turma::getHrInicioTime()
{
  return HoraEmMinutos(_hrInicio);
}

std::string Turma::getHrFim()
{
  return _hrFim;
}

int Turma::getHrFimTime()
{
  return HoraEmMinutos(_hrFim);
}

std::string Turma::getDiasSemana()
{
  return _diasSemana;
}

std::vector<int> Turma::getListaDiasSemana()
{
  std::vector<int> listaDiasSemana; // "2,4,6" -> [2, 4, 6] Segunda, Quarta e Sexta
  std::string diasSemana = _diasSemana;

  while (diasSemana.find(",") != std::string::npos)
  {
    listaDiasSemana.push_back(std::stoi(diasSemana.substr(0, diasSemana.find(","))));
    diasSemana = diasSemana.substr(diasSemana.find(",") + 1);
  }
  listaDiasSemana.push_back(std::stoi(diasSemana)); 

  return listaDiasSemana;
}

void Turma::setChaveTur(int chaveTur)
{
  _chaveTur = chaveTur;
}

void Turma::setChaveUsu(int chaveUsu)
{
  _chaveUsu = chaveUsu;
}

void Turma::setChaveMod(int chaveMod)
{
  _chaveMod = chaveMod;
}

void Turma::setHrInicio(std::string hrInicio)
{
  _hrInicio = hrInicio;
}

void Turma::setHrFim(std::string hrFim)
{
  _hrFim = hrFim;
}

void Turma::setDiasSemana(std::string diasSemana)
{
  _diasSemana = diasSemana;
}

Turma Turma::fromDatabase(PGresult *res, int row)
{
  int chaveTur = std::stoi(PQgetvalue(res, row, 0));
  int chaveUsu = std::stoi(PQgetvalue(res, row, 1));
  int chaveMod = std::stoi(PQgetvalue(res, row, 2));
  std::string hrInicio = PQgetvalue(res, row, 3);
  std::string hrFim = PQgetvalue(res, row, 4);
  std::string diasSemana = PQgetvalue(res, row, 5);

  return Turma(chaveTur, chaveUsu, chaveMod, hrInicio, hrFim, diasSemana);
}

Turma *Turma::fromDatabaseToPtr(PGresult *res, int row)
{
  int chaveTur = std::stoi(PQgetvalue(res, row, 0));
  int chaveUsu = (PQgetvalue(res, row, 1) == NULL ? -1 : std::stoi(PQgetvalue(res, row, 1)));
  int chaveMod = std::stoi(PQgetvalue(res, row, 2));
  std::string hrInicio = PQgetvalue(res, row, 3);
  std::string hrFim = PQgetvalue(res, row, 4);
  std::string diasSemana = PQgetvalue(res, row, 5);

  return new Turma(chaveTur, chaveUsu, chaveMod, hrInicio, hrFim, diasSemana);
}