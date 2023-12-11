#include "modalidade.h"
#include "database.h"
#include "global.h"

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
  return  Modalidade(std::stoi(Database::value(res, row, "CHAVEMOD")), Database::value(res, row, "NOME"));
}

Modalidade* Modalidade::fromDatabaseToPtr(PGresult *res, int row)
{
  return new Modalidade(std::stoi(Database::value(res, row, "CHAVEMOD")), Database::value(res, row, "NOME"));
}