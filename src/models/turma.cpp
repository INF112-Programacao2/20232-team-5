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