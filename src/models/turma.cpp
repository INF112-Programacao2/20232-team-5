#include "turma.h"

Turma::Turma(int chaveTur, int chavePes, int chaveMod, std::string hrInicio, std::string hrFim, std::string diasSemana)
    : _chaveTur(chaveTur), _chavePes(chavePes), _chaveMod(chaveMod),
      _hrInicio(hrInicio), _hrFim(hrFim), _diasSemana(diasSemana)
{
}

int Turma::getChaveTur()
{
  return _chaveTur;
}

int Turma::getChavePes()
{
  return _chavePes;
}

int Turma::getChaveMod()
{
  return _chaveMod;
}

std::string Turma::getHrInicio()
{
  return _hrInicio;
}

std::string Turma::getHrFim()
{
  return _hrFim;
}

std::string Turma::getDiasSemana()
{
  return _diasSemana;
}

void Turma::setChaveTur(int chaveTur)
{
  _chaveTur = chaveTur;
}

void Turma::setChavePes(int chavePes)
{
  _chavePes = chavePes;
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