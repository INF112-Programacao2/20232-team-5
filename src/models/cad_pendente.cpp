#include "cad_pendente.h"

// Construtor para cadastro externo de professor (novo usuário)
CadPendente::CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha, char tipo) : _chaveCad(chaveCad), _nome(nome), _apelido(apelido), _dtNascimento(dtNascimento), _cpf(cpf), _rg(rg), _sexo(sexo), _login(login), _senha(senha), _tipo(tipo)
{
  _tipoCadastro = TipoCadastro::Externo;
}

// Construtor para cadastro externo de aluno (novo usuário, necessita informar a modalidade)
CadPendente::CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha, char tipo, int chaveMod) : _chaveCad(chaveCad), _nome(nome), _apelido(apelido), _dtNascimento(dtNascimento), _cpf(cpf), _rg(rg), _sexo(sexo), _login(login), _senha(senha), _tipo(tipo), _chaveMod(chaveMod)
{
  _tipoCadastro = TipoCadastro::Externo;
}

// Construtor para cadastro interno de professor (usuário já existente)
CadPendente::CadPendente(int chaveCad, int chaveUsu, char tipo) : _chaveCad(chaveCad), _chaveUsu(chaveUsu), _tipo(tipo)
{
  _tipoCadastro = TipoCadastro::Interno;
}

// Construtor para cadastro interno de aluno (usuário já existente, necessita informar a modalidade)
CadPendente::CadPendente(int chaveCad, int chaveUsu, char tipo, int chaveMod) : _chaveCad(chaveCad), _chaveUsu(chaveUsu), _tipo(tipo), _chaveMod(chaveMod)
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

std::string CadPendente::getRg()
{
  return _rg;
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

void CadPendente::setRg(std::string rg)
{
  _rg = rg;
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
  setRg(usuario->getRg());
  setSexo(usuario->getSexo());
  setLogin(usuario->getLogin());
  setSenha(usuario->getSenha());
}

void CadPendente::toQueryParams(char paramValues[][1000])
{
  /*std::sprintf(paramValues[0], "%d", _chaveCad);
  std::sprintf(paramValues[1], "%s", _nome);
  std::sprintf(paramValues[2], "%s", _apelido);
  std::sprintf(paramValues[3], "%s", _dtNascimento);
  std::sprintf(paramValues[4], "%s", _cpf);*/
}