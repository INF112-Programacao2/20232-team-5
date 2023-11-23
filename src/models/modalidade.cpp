#include "modalidade.h"

Modalidade::Modalidade(int chaveMod, std::string nome)
    : _chaveMod(chaveMod), _nome(nome)
{
}

int Modalidade::getChaveMod() const
{
  return _chaveMod;
}

std::string Modalidade::getNome() const
{
  return _nome;
}

void Modalidade::setChaveMod(int chaveMod)
{
  _chaveMod = chaveMod;
}

void Modalidade::setNome(std::string nome)
{
  _nome = nome;
}