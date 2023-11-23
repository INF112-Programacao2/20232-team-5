#include "perfil.h"

Perfil::Perfil(int chavePer, int chaveUsu, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string nome, std::string login, std::string senha, char tipo) : Usuario(chaveUsu, apelido, dtNascimento, cpf, rg, sexo, nome, login, senha), _chavePer(chavePer), _tipo(tipo)
{
}

int Perfil::getChavePer() const
{
  return _chavePer;
}

char Perfil::getTipo() const
{
  return _tipo;
}

void Perfil::setChavePer(int chavePer)
{
  _chavePer = chavePer;
}

void Perfil::setTipo(char tipo)
{
  _tipo = tipo;
}