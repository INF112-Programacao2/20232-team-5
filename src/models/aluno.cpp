#include "aluno.h"
#include "global.h"

Aluno::Aluno(int chaveAlu, int chaveUsu, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha, int chaveGrd, int numAulas)
    : Usuario(chaveUsu, nome, apelido, dtNascimento, cpf, rg, sexo, login, senha),
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

Aluno *Aluno::fromUsuario(Usuario *usuario)
{
  return new Aluno(
      nullnum,
      usuario->getChaveUsu(),
      usuario->getNome(),
      usuario->getApelido(),
      usuario->getDtNascimento(),
      usuario->getCpf(),
      usuario->getRg(),
      usuario->getSexo(),
      usuario->getLogin(),
      usuario->getSenha(),
      nullnum,
      0);
}