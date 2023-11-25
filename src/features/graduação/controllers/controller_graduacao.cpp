#include "controller_graduacao.h"
#include <iostream>

ControllerGraduacao::ControllerGraduacao(Session *session)
    : _session(session)
{}

RetornoController ControllerGraduacao::realizaCadastro()
{
  std::string nome;
  int ordem;
  int minAulas;

  // Solicitar valores ao usuário
  std::cout << "CADASTRO" << std::endl;

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
  Graduacao *graduacao = new Graduacao(0, nome, ordem, minAulas);

  // Salva a graduação
  _session->getGraduacaoRepository()->save(graduacao);

  return RetornoController::Sucesso;
}

// Path src/features/autenticacao/controllers/controller_autenticacao.cpp