#include "aluno.h"

Aluno::Aluno(int chaveAlu, int chaveUsu, int chavePer, int chaveGrd, int numAulas,
             std::string apelido, std::string dtNascimento,
             std::string cpf, std::string rg, char sexo,
             std::string nome, std::string login, std::string senha, char tipo)
    : Perfil(chavePer, chaveUsu, apelido, dtNascimento, cpf, rg, sexo, nome, login, senha, tipo),
      _chaveAlu(chaveAlu), _chaveGrd(chaveGrd), _numAulas(numAulas)
{
}

int Aluno::getChaveAlu() const
{
  return _chaveAlu;
}

int Aluno::getChaveGrd() const
{
  return _chaveGrd;
}

int Aluno::getNumAulas() const
{
  return _numAulas;
}

void Aluno::setChaveAlu(int chaveAlu)
{
  _chaveAlu = chaveAlu;
}

void Aluno::setChaveGrd(int chaveGrd)
{
  _chaveGrd = chaveGrd;
}

void Aluno::setNumAulas(int numAulas)
{
  _numAulas = numAulas;
}