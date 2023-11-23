#include "aluno.h"

Aluno::Aluno(int chaveAlu, int chaveUsu, int chavePer,
             std::string nome, int chaveGrd, int numAulas,
             std::string apelido, std::string dtNascimento,
             std::string cpf, std::string rg, char sexo, std::string login, std::string senha, char tipo)
    : Perfil(chavePer, chaveUsu, nome, apelido, dtNascimento, cpf, rg, sexo, login, senha, tipo),
      _chaveAlu(chaveAlu), _chaveGrd(chaveGrd), _numAulas(numAulas)
{
}

int Aluno::getChaveAlu()
{
  return _chaveAlu;
}

int Aluno::getChaveGrd()
{
  return _chaveGrd;
}

int Aluno::getNumAulas()
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