#ifndef INF112_USUARIO_H
#define INF112_USUARIO_H
#include <string>
#include <vector>
#include <libpq-fe.h>
#include "enums.h"

class CadPendente;

class Usuario
{
private:
  int _chaveUsu;
  std::string _nome;
  std::string _apelido;
  std::string _dtNascimento;
  std::string _cpf;
  char _sexo;
  std::string _login;
  std::string _senha;
  std::vector<TipoPerfil> _perfilList;

public:
  Usuario(int chaveUsu, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, char sexo, std::string login, std::string senha);

  // Getters
  int getChaveUsu();
  std::string getNome();
  std::string getApelido();
  std::string getDtNascimento();
  std::string getCpf();
  char getSexo();
  std::string getLogin();
  std::string getSenha();
  std::vector<TipoPerfil> getPerfilList();

  // Setters
  void
  setChaveUsu(int chaveUsu);
  void setNome(std::string nome);
  void setApelido(std::string apelido);
  void setDtNascimento(std::string dtNascimento);
  void setCpf(std::string cpf);
  void setSexo(char sexo);
  void setLogin(std::string login);
  void setSenha(std::string senha);
  void setPerfilList(std::vector<TipoPerfil> perfilList);

  // Outros
  void addPerfil(TipoPerfil perfil);

  // Conversion
  static Usuario *fromDatabaseToPtr(PGresult *res, int row);
  static Usuario fromDatabase(PGresult *res, int row);
  static Usuario *fromCadPendente(CadPendente *cad);
};

#endif