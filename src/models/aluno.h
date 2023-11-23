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
  Aluno(int chaveAlu, int chaveUsu, int chavePer,
        std::string nome, int chaveGrd, int numAulas,
        std::string apelido, std::string dtNascimento,
        std::string cpf, std::string rg, char sexo, std::string login, std::string senha, char tipo);

  // Getters
  int getChaveAlu();
  int getChaveGrd();
  int getNumAulas();

  // Setters
  void setChaveAlu(int chaveAlu);
  void setChaveGrd(int chaveGrd);
  void setNumAulas(int numAulas);
};

#endif