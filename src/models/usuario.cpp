#include "usuario.h"

// Construtor
Usuario::Usuario(int chaveUsu, std::string apelido, std::string dtNascimento,
                 std::string cpf, std::string rg, char sexo, std::string nome,
                 std::string login, std::string senha)
    : _chaveUsu(chaveUsu), _apelido(apelido), _dtNascimento(dtNascimento),
      _cpf(cpf), _rg(rg), _sexo(sexo), _nome(nome), _login(login), _senha(senha)
{
}

// Getters
int Usuario::getChaveUsu() const
{
  return _chaveUsu;
}

std::string Usuario::getApelido() const
{
  return _apelido;
}

std::string Usuario::getDtNascimento() const
{
  return _dtNascimento;
}

std::string Usuario::getCpf() const
{
  return _cpf;
}

std::string Usuario::getRg() const
{
  return _rg;
}

char Usuario::getSexo() const
{
  return _sexo;
}

std::string Usuario::getNome() const
{
  return _nome;
}

std::string Usuario::getLogin() const
{
  return _login;
}

std::string Usuario::getSenha() const
{
  return _senha;
}

// Setters
void Usuario::setChaveUsu(int chaveUsu)
{
  _chaveUsu = chaveUsu;
}

void Usuario::setApelido(std::string apelido)
{
  _apelido = apelido;
}

void Usuario::setDtNascimento(std::string dtNascimento)
{
  _dtNascimento = dtNascimento;
}

void Usuario::setCpf(std::string cpf)
{
  _cpf = cpf;
}

void Usuario::setRg(std::string rg)
{
  _rg = rg;
}

void Usuario::setSexo(char sexo)
{
  _sexo = sexo;
}

void Usuario::setNome(std::string nome)
{
  _nome = nome;
}

void Usuario::setLogin(std::string login)
{
  _login = login;
}

void Usuario::setSenha(std::string senha)
{
  _senha = senha;
}