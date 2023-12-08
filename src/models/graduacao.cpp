#include "graduacao.h"

Graduacao::Graduacao(int chaveGrd, int chaveMod, std::string nome, int ordem, int minAulas)
    : _chaveGrd(chaveGrd), _chaveMod(chaveMod), _nome(nome), ordem(ordem), minAulas(minAulas)
{
}

int Graduacao::getChaveGrd()
{
  return _chaveGrd;
}

int Graduacao::getChaveMod()
{
  return _chaveMod;
}

std::string Graduacao::getNome()
{
  return _nome;
}

int Graduacao::getOrdem()
{
  return ordem;
}

int Graduacao::getMinAulas()
{
  return minAulas;
}

void Graduacao::setChaveGrd(int chaveGrd)
{
  _chaveGrd = chaveGrd;
}

void Graduacao::setChaveMod(int chaveMod)
{
  _chaveMod = chaveMod;
}

void Graduacao::setNome(std::string nome)
{
  _nome = nome;
}

void Graduacao::setOrdem(int ordem)
{
  this->ordem = ordem;
}

void Graduacao::setMinAulas(int minAulas)
{
  this->minAulas = minAulas;
}

// Path src/features/gradua%C3%A7%C3%A3o/graduacao.cpp