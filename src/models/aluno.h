#ifndef INF112_ALUNO_H
#define INF112_ALUNO_H

#include "perfil.h"

class Aluno : public Perfil
{
private:
  int _chaveAlu;
  int _chaveGrd;
  int _numAulas;

public:
  Aluno(int chaveAlu, int chaveUsu, int chavePer, int chaveGrd, int numAulas,
        std::string apelido, std::string dtNascimento,
        std::string cpf, std::string rg, char sexo,
        std::string nome, std::string login, std::string senha, char tipo);

  // Getters
  int getChaveAlu() const;
  int getChaveGrd() const;
  int getNumAulas() const;

  // Setters
  void setChaveAlu(int chaveAlu);
  void setChaveGrd(int chaveGrd);
  void setNumAulas(int numAulas);
};

#endif INF112_ALUNO_H