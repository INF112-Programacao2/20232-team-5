#include "perfil.h"
#include <string>

Perfil::Perfil(int chavePer, char tipo) : _chavePer(chavePer), _tipo(tipo)
{
}

int Perfil::getChavePer()
{
  return _chavePer;
}

char Perfil::getTipo()
{
  return _tipo;
}

void Perfil::setChavePer(int chavePer)
{
  _chavePer = chavePer;
}

void Perfil::setTipo(char tipo)
{
  _tipo = tipo;
}

Perfil Perfil::fromDatabase(PGresult *res, int row)
{
  return Perfil(
      std::atoi(PQgetvalue(res, row, 0)),
      PQgetvalue(res, row, 2)[0]);
}