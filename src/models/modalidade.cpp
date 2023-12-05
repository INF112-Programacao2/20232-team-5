#include "modalidade.h"

Modalidade::Modalidade(int chaveMod, std::string nome)
    : _chaveMod(chaveMod), _nome(nome)
{
}

int Modalidade::getChaveMod()
{
  return _chaveMod;
}

std::string Modalidade::getNome()
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

Modalidade Modalidade::fromDatabase(PGresult *res, int row)
{
  return Modalidade(
      std::atoi(PQgetvalue(res, row, 0)),
      PQgetvalue(res, row, 2));
}