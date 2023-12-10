#ifndef INF112_DATA_USUARIO_H
#define INF112_DATA_USUARIO_H
#include <vector>
#include "database.h"
#include "usuario.h"

class DataUsuario
{
private:
  Database *_database;

public:
  DataUsuario(Database *database);
  void salvarSenha(int chaveUsu, std::string senha);
  Usuario *buscaUsuarioByChave(int chaveUsu);
  int criaUsuario(Usuario *usuario);
  void editaNome(int chaveUsu, std::string nome);
  void editaApelido(int chaveUsu, std::string apelido);
  void editaDtNascimento(int chaveUsu, std::string dtNascimento);
  void editaCpf(int chaveUsu, std::string cpf);
  void editaSexo(int chaveUsu, char sexo);
  void editaLogin(int chaveUsu, std::string login);
  std::vector<Usuario> buscaListaUsuario();
};

#endif