#include "controller_graduacao.h"
#include <iostream>
#include "graduacao.h"
#include "global.h"

ControllerGraduacao::ControllerGraduacao(Session *session, DataGraduacao *dataGraduacao)
    : _session(session), _dataGraduacao(dataGraduacao)
{
}

RetornoController ControllerGraduacao::realizaCadastro()
{
  std::string nome;
  int ordem;
  int minAulas;

  // Solicitar valores ao usuário
  std::cout << "CADASTRO" << std::endl;

  std::cout << "Digite a chave da modalidade: ";
  int chaveMod = readVal<int>(
      [&](int chaveMod)
      {
        if (chaveMod < 0)
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });

  std::cout << "Digite o nome: ";
  nome = readLine();

  std::cout << "Digite a ordem: ";
  ordem = readVal<int>(
      [&](int ordem)
      {
        if (ordem < 0)
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });

  std::cout << "Digite o número mínimo de aulas: ";
  minAulas = readVal<int>(
      [&](int minAulas)
      {
        if (minAulas < 0)
        {
          std::cout << "Opção inválida!" << std::endl;
          return false;
        }
        return true;
      });

  // Cria a graduação
  Graduacao *graduacao = new Graduacao(nullnum, chaveMod, nome, ordem, minAulas);

  // Salva a graduação
  _dataGraduacao->cadastraGraduacao(graduacao);

  return RetornoController::Completo;
}

// Path src/features/autenticacao/controllers/controller_autenticacao.cpp