﻿#include "controller_graduacao.h"
#include <iostream>
#include "graduacao.h"
#include "global.h"

ControllerGraduacao::ControllerGraduacao(Session *session, DataGraduacao *dataGraduacao)
    : _session(session), _dataGraduacao(dataGraduacao)
{
}

RetornoController ControllerGraduacao::realizaCadastro()
{
  Graduacao *graduacao = nullptr;
  handleExecution(
      [&]()
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
        graduacao = new Graduacao(nullnum, chaveMod, nome, ordem, minAulas);

        // Salva a graduação
        _dataGraduacao->cadastraGraduacao(graduacao);
        std::cout << "Graduação cadastrada com sucesso!" << std::endl;
      });

  if (graduacao)
    delete graduacao;
  return RetornoController::Completo;
}

// listar as graduações cadastradas no sistema

RetornoController ControllerGraduacao::realizaListagem()
{
  return handleExecution(
      [&]()
      {
        std::cout << "LISTAGEM" << std::endl;

        // Lista as graduações
        _dataGraduacao->listarGraduacao();
      });
}

// editar uma graduação buscando pela chaveGdr cadastrada no sistema

RetornoController ControllerGraduacao::realizaEdicao()
{
  Graduacao *graduacao = nullptr;
  handleExecution(
      [&]()
      {
        std::string nome;
        int ordem;
        int minAulas;

        // Solicitar valores ao usuário
        std::cout << "EDIÇÃO" << std::endl;

        std::cout << "Digite a chave da graduação: ";
        int chaveGdr = readVal<int>(
            [&](int chaveGdr)
            {
              if (chaveGdr < 0)
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
        graduacao = new Graduacao(chaveGdr, nullnum, nome, ordem, minAulas);

        // Salva a graduação
        _dataGraduacao->editarGraduacao(graduacao);
        std::cout << "Graduação editada com sucesso!" << std::endl;
      });

  if (graduacao)
    delete graduacao;
  return RetornoController::Completo;
}

// excluir uma graduação buscando pela chaveGdr cadastrada no sistema

RetornoController ControllerGraduacao::realizaRemocao()
{
  Graduacao *graduacao = nullptr;
  handleExecution(
      [&]()
      {
        std::cout << "EXCLUSÃO" << std::endl;

        std::cout << "Digite a chave da graduação: ";
        int chaveGdr = readVal<int>(
            [&](int chaveGdr)
            {
              if (chaveGdr < 0)
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            });

        // Cria a graduação
        graduacao = new Graduacao(chaveGdr, nullnum, nullstr, nullnum, nullnum);

        // exclui a graduação
        _dataGraduacao->excluirGraduacao(graduacao);
        std::cout << "Graduação excluída com sucesso!" << std::endl;
      });

  if (graduacao)
    delete graduacao;
  return RetornoController::Completo;
}
