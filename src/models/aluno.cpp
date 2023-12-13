#include "aluno.h"
#include "global.h"
#include <libpq-fe.h>
#include "database.h"

Aluno::Aluno(int chaveAlu, int chaveUsu, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, char sexo, std::string login, std::string senha, int chaveGrd, int numAulas)
    : Usuario(chaveUsu, nome, apelido, dtNascimento, cpf, sexo, login, senha),
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
      usuario->getSexo(),
      usuario->getLogin(),
      usuario->getSenha(),
      nullnum,
      0);
}

Aluno Aluno::fromDatabase(PGresult *res, int row)
{
  return Aluno(
      std::stoi(Database::value(res, row, "CHAVEALU")),
      std::stoi(Database::value(res, row, "CHAVEUSU")),
      Database::value(res, row, "NOME"),
      Database::value(res, row, "APELIDO"),
      Database::value(res, row, "DTNASCIMENTO"),
      Database::value(res, row, "CPF"),
      Database::value(res, row, "SEXO")[0],
      Database::value(res, row, "LOGIN"),
      Database::value(res, row, "SENHA"),
      std::stoi(Database::value(res, row, "CHAVEGRD")),
      std::stoi(Database::value(res, row, "NUMAULAS")));
}

Aluno *Aluno::fromDatabaseToPtr(PGresult *res, int row)
{
  return new Aluno(
      std::stoi(Database::value(res, row, "CHAVEALU")),
      std::stoi(Database::value(res, row, "CHAVEUSU")),
      Database::value(res, row, "NOME"),
      Database::value(res, row, "APELIDO"),
      Database::value(res, row, "DTNASCIMENTO"),
      Database::value(res, row, "CPF"),
      Database::value(res, row, "SEXO")[0],
      Database::value(res, row, "LOGIN"),
      Database::value(res, row, "SENHA"),
      std::stoi(Database::value(res, row, "CHAVEGRD")),
      std::stoi(Database::value(res, row, "NUMAULAS")));
}