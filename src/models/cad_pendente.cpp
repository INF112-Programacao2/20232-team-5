#include "cad_pendente.h"
#include <iostream>
#include "database.h"
#include "global.h"

// Construtor para receber do banco (todos os dados)
CadPendente::CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, char sexo, std::string login, std::string senha, char tipo, int chaveMod, int chaveUsu, TipoCadastro tipoCadastro) : _chaveCad(chaveCad), _nome(nome), _apelido(apelido), _dtNascimento(dtNascimento), _cpf(cpf), _sexo(sexo), _login(login), _senha(senha), _tipo(tipo), _chaveMod(chaveMod), _chaveUsu(chaveUsu), _tipoCadastro(tipoCadastro) {}

// Construtor para cadastro externo de professor (novo usuário)
CadPendente::CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, char sexo, std::string login, std::string senha, char tipo) : _chaveCad(chaveCad), _nome(nome), _apelido(apelido), _dtNascimento(dtNascimento), _cpf(cpf), _sexo(sexo), _login(login), _senha(senha), _tipo(tipo), _chaveMod(nullnum), _chaveUsu(nullnum)
{
  _tipoCadastro = TipoCadastro::Externo;
}

// Construtor para cadastro externo de aluno (novo usuário, necessita informar a modalidade)
CadPendente::CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, char sexo, std::string login, std::string senha, char tipo, int chaveMod) : _chaveCad(chaveCad), _nome(nome), _apelido(apelido), _dtNascimento(dtNascimento), _cpf(cpf), _sexo(sexo), _login(login), _senha(senha), _tipo(tipo), _chaveMod(chaveMod), _chaveUsu(nullnum)
{
  _tipoCadastro = TipoCadastro::Externo;
}

// Construtor para cadastro interno de professor (usuário já existente)
CadPendente::CadPendente(int chaveCad, int chaveUsu, char tipo) : _chaveCad(chaveCad), _nome(nullstr), _apelido(nullstr), _dtNascimento(nullstr), _cpf(nullstr), _sexo(nullchar), _login(nullstr), _senha(nullstr), _tipo(tipo), _chaveMod(nullnum), _chaveUsu(chaveUsu)
{
  _tipoCadastro = TipoCadastro::Interno;
}

// Construtor para cadastro interno de aluno (usuário já existente, necessita informar a modalidade)
CadPendente::CadPendente(int chaveCad, int chaveUsu, char tipo, int chaveMod) : _chaveCad(chaveCad), _nome(nullstr), _apelido(nullstr), _dtNascimento(nullstr), _cpf(nullstr), _sexo(nullchar), _login(nullstr), _senha(nullstr), _tipo(tipo), _chaveMod(chaveMod), _chaveUsu(chaveUsu)
{
  _tipoCadastro = TipoCadastro::Interno;
}

int CadPendente::getChaveCad()
{
  return _chaveCad;
}

std::string CadPendente::getNome()
{
  return _nome;
}

std::string CadPendente::getApelido()
{
  return _apelido;
}

std::string CadPendente::getDtNascimento()
{
  return _dtNascimento;
}

std::string CadPendente::getCpf()
{
  return _cpf;
}

char CadPendente::getSexo()
{
  return _sexo;
}

std::string CadPendente::getLogin()
{
  return _login;
}

std::string CadPendente::getSenha()
{
  return _senha;
}

char CadPendente::getTipo()
{
  return _tipo;
}

int CadPendente::getChaveMod()
{
  return _chaveMod;
}

int CadPendente::getChaveUsu()
{
  return _chaveUsu;
}

TipoCadastro CadPendente::getTipoCadastro()
{
  return _tipoCadastro;
}

void CadPendente::setChaveCad(int chaveCad)
{
  _chaveCad = chaveCad;
}

void CadPendente::setNome(std::string nome)
{
  _nome = nome;
}

void CadPendente::setApelido(std::string apelido)
{
  _apelido = apelido;
}

void CadPendente::setDtNascimento(std::string dtNascimento)
{
  _dtNascimento = dtNascimento;
}

void CadPendente::setCpf(std::string cpf)
{
  _cpf = cpf;
}

void CadPendente::setSexo(char sexo)
{
  _sexo = sexo;
}

void CadPendente::setLogin(std::string login)
{
  _login = login;
}

void CadPendente::setSenha(std::string senha)
{
  _senha = senha;
}

void CadPendente::setTipo(char tipo)
{
  _tipo = tipo;
}

void CadPendente::setChaveMod(int chaveMod)
{
  _chaveMod = chaveMod;
}

void CadPendente::setChaveUsu(int chaveUsu)
{
  _chaveUsu = chaveUsu;
}

void CadPendente::setTipoCadastro(TipoCadastro tipoCadastro)
{
  _tipoCadastro = tipoCadastro;
}

void CadPendente::setFromUsuario(Usuario *usuario)
{
  setNome(usuario->getNome());
  setApelido(usuario->getApelido());
  setDtNascimento(usuario->getDtNascimento());
  setCpf(usuario->getCpf());
  setSexo(usuario->getSexo());
  setLogin(usuario->getLogin());
  setSenha(usuario->getSenha());
}

CadPendente CadPendente::fromDatabase(PGresult *res, int row)
{
  char sexo = Database::value(res, row, "SEXO") == nullstr ? nullchar : Database::value(res, row, "SEXO")[0];
  int chaveMod = Database::value(res, row, "CHAVEMOD") == nullstr ? nullnum : std::stoi(Database::value(res, row, "CHAVEMOD"));
  int chaveUsu = Database::value(res, row, "CHAVEUSU") == nullstr ? nullnum : std::stoi(Database::value(res, row, "CHAVEUSU"));

  return CadPendente(
      std::stoi(Database::value(res, row, "CHAVECAD")),
      Database::value(res, row, "NOME"),
      Database::value(res, row, "APELIDO"),
      Database::value(res, row, "DTNASCIMENTO"),
      Database::value(res, row, "CPF"),
      sexo,
      Database::value(res, row, "LOGIN"),
      Database::value(res, row, "SENHA"),
      Database::value(res, row, "TIPO")[0],
      chaveMod,
      chaveUsu,
      static_cast<TipoCadastro>(
          Database::value(res, row, "TIPOCADASTRO")[0]));
}

CadPendente *CadPendente::fromDatabaseToPtr(PGresult *res, int row)
{
  char sexo = Database::value(res, row, "SEXO") == nullstr ? nullchar : Database::value(res, row, "SEXO")[0];
  int chaveMod = Database::value(res, row, "CHAVEMOD") == nullstr ? nullnum : std::stoi(Database::value(res, row, "CHAVEMOD"));
  int chaveUsu = Database::value(res, row, "CHAVEUSU") == nullstr ? nullnum : std::stoi(Database::value(res, row, "CHAVEUSU"));

  return new CadPendente(
      std::stoi(Database::value(res, row, "CHAVECAD")),
      Database::value(res, row, "NOME"),
      Database::value(res, row, "APELIDO"),
      Database::value(res, row, "DTNASCIMENTO"),
      Database::value(res, row, "CPF"),
      sexo,
      Database::value(res, row, "LOGIN"),
      Database::value(res, row, "SENHA"),
      Database::value(res, row, "TIPO")[0],
      chaveMod,
      chaveUsu,
      static_cast<TipoCadastro>(
          Database::value(res, row, "TIPOCADASTRO")[0]));
}