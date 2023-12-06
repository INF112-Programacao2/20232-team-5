#include "usuario.h"
#include "database.h"

// Construtor
Usuario::Usuario(int chaveUsu, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha) : _chaveUsu(chaveUsu), _nome(nome), _apelido(apelido), _dtNascimento(dtNascimento), _cpf(cpf), _rg(rg), _sexo(sexo), _login(login), _senha(senha)
{
}

// Getters
int Usuario::getChaveUsu()
{
  return _chaveUsu;
}

std::string Usuario::getApelido()
{
  return _apelido;
}

std::string Usuario::getDtNascimento()
{
  return _dtNascimento;
}

std::string Usuario::getCpf()
{
  return _cpf;
}

std::string Usuario::getRg()
{
  return _rg;
}

char Usuario::getSexo()
{
  return _sexo;
}

std::string Usuario::getNome()
{
  return _nome;
}

std::string Usuario::getLogin()
{
  return _login;
}

std::string Usuario::getSenha()
{
  return _senha;
}

std::vector<Perfil> Usuario::getPerfilList()
{
  return _perfilList;
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

void Usuario::setPerfilList(std::vector<Perfil> perfilList)
{
  _perfilList = perfilList;
}

void Usuario::addPerfil(Perfil perfil)
{
  _perfilList.push_back(perfil);
}

Usuario *Usuario::fromDatabase(PGresult *res, int row)
{
  return new Usuario(
      std::stoi(Database::value(res, row, "CHAVEUSU")),
      Database::value(res, row, "NOME"),
      Database::value(res, row, "APELIDO"),
      Database::value(res, row, "DTNASCIMENTO"),
      Database::value(res, row, "CPF"),
      Database::value(res, row, "RG"),
      Database::value(res, row, "SEXO")[0],
      Database::value(res, row, "LOGIN"),
      Database::value(res, row, "SENHA"));
}