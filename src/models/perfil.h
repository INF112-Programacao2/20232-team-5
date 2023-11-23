#ifndef INF112_PERFIL_H
#define INF112_PERFIL_H

#include "usuario.h"

class Perfil : public Usuario
{
private:
  int _chavePer;
  char _tipo;

public:
  Perfil(int chavePer, int chaveUsu, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string nome, std::string login, std::string senha, char tipo);

  int getChavePer() const;
  char getTipo() const;

  void setChavePer(int chavePer);
  void setTipo(char tipo);
};

#endif