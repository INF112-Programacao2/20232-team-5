#include "perfil.h"

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