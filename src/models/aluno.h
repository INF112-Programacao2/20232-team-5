#ifndef INF112_ALUNO_H
#define INF112_ALUNO_H

#include "usuario.h"
#include <string>

class Aluno : public Usuario
{
private:
  int _chaveAlu;
  int _chaveGrd;
  int _numAulas;

public:
  Aluno(int chaveAlu, int chaveUsu, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha, int chaveGrd, int numAulas);

  // Getters
  int getChaveAlu();
  int getChaveGrd();
  int getNumAulas();

  // Setters
  void setChaveAlu(int chaveAlu);
  void setChaveGrd(int chaveGrd);
  void setNumAulas(int numAulas);

  // Conversion
  static Aluno *fromUsuario(Usuario *usuario);
  static Aluno fromDatabase(PGresult *res, int row);
};

#endif