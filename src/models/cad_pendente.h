#ifndef INF112_CAD_PENDENTE_H
#define INF112_CAD_PENDENTE_H
#include <string>
#include "usuario.h"

enum TipoCadastro
{
  Externo = 'E',
  Interno = 'I'
};

class CadPendente
{
private:
  int _chaveCad;
  std::string _nome;
  std::string _apelido;
  std::string _dtNascimento;
  std::string _cpf;
  std::string _rg;
  char _sexo;
  std::string _login;
  std::string _senha;
  char _tipo;
  int _chaveMod;
  int _chaveUsu;
  TipoCadastro _tipoCadastro;

public:
  // Construtor para receber do banco (todos os dados)
  CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha, char tipo, int chaveMod, int chaveUsu, TipoCadastro tipoCadastro);
  // Construtor para cadastro externo de professor (novo usuário)
  CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha, char tipo);
  // Construtor para cadastro externo de aluno (novo usuário, necessita informar a modalidade)
  CadPendente(int chaveCad, std::string nome, std::string apelido, std::string dtNascimento, std::string cpf, std::string rg, char sexo, std::string login, std::string senha, char tipo, int chaveMod);
  // Construtor para cadastro interno de professor (usuário já existente)
  CadPendente(int chaveCad, int chaveUsu, char tipo);
  // Construtor para cadastro interno de aluno (usuário já existente, necessita informar a modalidade)
  CadPendente(int chaveCad, int chaveUsu, char tipo, int chaveMod);

  // Getters
  int getChaveCad();
  std::string getNome();
  std::string getApelido();
  std::string getDtNascimento();
  std::string getCpf();
  std::string getRg();
  char getSexo();
  std::string getLogin();
  std::string getSenha();
  char getTipo();
  int getChaveMod();
  int getChaveUsu();
  TipoCadastro getTipoCadastro();

  // Setters
  void setChaveCad(int chaveCad);
  void setNome(std::string nome);
  void setApelido(std::string apelido);
  void setDtNascimento(std::string dtNascimento);
  void setCpf(std::string cpf);
  void setRg(std::string rg);
  void setSexo(char sexo);
  void setLogin(std::string login);
  void setSenha(std::string senha);
  void setTipo(char tipo);
  void setChaveMod(int chaveMod);
  void setChaveUsu(int chaveUsu);
  void setTipoCadastro(TipoCadastro tipoCadastro);
  void setFromUsuario(Usuario *usuario);

  // Conversion
  static CadPendente fromDatabase(PGresult *res, int row);
  static CadPendente *fromDatabaseToPtr(PGresult *res, int row);
};

#endif