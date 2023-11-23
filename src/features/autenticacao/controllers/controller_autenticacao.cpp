#include <iostream>
#include "controller_autenticacao.h"

// Classe responsável por controlar as operações de autenticação

ControllerAutenticacao::ControllerAutenticacao(Session *session) : _session(session) {}

RetornoController ControllerAutenticacao::realizaCadastro()
{
  std::string apelido;
  std::string dtNascimento;
  std::string cpf;
  std::string rg;
  char sexo;
  std::string nome;
  std::string login;
  std::string senha;
  char tipo;

  // Solicitar valores ao usuário
  std::cout << "CADASTRO" << std::endl;

  std::cout << "Digite o nome: ";
  nome = readLine();

  std::cout << "Digite o apelido: ";
  apelido = readLine();

  std::cout << "Digite a data de nascimento: ";
  dtNascimento = readLine();

  std::cout << "Digite o CPF: ";
  cpf = readLine();

  std::cout << "Digite o RG: ";
  rg = readLine();

  std::cout << "Digite o sexo (M/F): ";
  sexo = readVal<char>(
      [&](char sexo)
      {
        if (sexo != 'M' && sexo != 'F')
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });

  std::cout << "Digite o login: ";
  login = readLine();

  std::cout << "Digite a senha: ";
  senha = readLine();

  std::cout << "Deseja solicitar cadastro como cliente (C) ou professor (P)? ";
  tipo = readVal<char>(
      [&](char tipo)
      {
        if (tipo != 'C' && tipo != 'P')
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });

  return RetornoController::Completo;
}