#include "graduacao.h"

Graduacao::Graduacao(int chaveGrad, std::string nome, int ordem, int minAulas)
    : _chaveGrad(chaveGrad), _nome(nome), ordem(ordem), minAulas(minAulas)
{
}

int Graduacao::getChaveGrad()
{
  return _chaveGrad;
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

void Graduacao::setChaveGrad(int chaveGrad)
{
  _chaveGrad = chaveGrad;
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