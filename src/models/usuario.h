#ifndef INF112_USUARIO_H
#define INF112_USUARIO_H
#include <string>

class Usuario
{
private:
  int _chaveUsu;
  std::string _apelido;
  std::string _dtNascimento;
  std::string _cpf;
  std::string _rg;
  char _sexo;
  std::string _nome;
  std::string _login;
  std::string _senha;

public:
  Usuario(int chaveUsu, std::string apelido, std::string dtNascimento,
          std::string cpf, std::string rg, char sexo, std::string nome, std::string login, std::string senha);

  // Getters
  int getChaveUsu() const;
  std::string getApelido() const;
  std::string getDtNascimento() const;
  std::string getCpf() const;
  std::string getRg() const;
  char getSexo() const;
  std::string getNome() const;
  std::string getLogin() const;
  std::string getSenha() const;

  // Setters
  void setChaveUsu(int chaveUsu);
  void setApelido(std::string apelido);
  void setDtNascimento(std::string dtNascimento);
  void setCpf(std::string cpf);
  void setRg(std::string rg);
  void setSexo(char sexo);
  void setNome(std::string nome);
  void setLogin(std::string login);
  void setSenha(std::string senha);
};

#endif