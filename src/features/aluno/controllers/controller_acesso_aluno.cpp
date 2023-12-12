#include "controller_acesso_aluno.h"
#include <vector>
#include "graduacao.h"
#include "modalidade.h"

ControllerAcessoAluno::ControllerAcessoAluno(Session *session, DataAluno *dataAluno, DataGraduacao *dataGraduacao, DataModalidade *dataModalidade) : _session(session), _dataAluno(dataAluno), _dataGraduacao(dataGraduacao), _dataModalidade(dataModalidade){};

RetornoController ControllerAcessoAluno::verDados()
{
  Aluno *aluno = _session->getSelectedAluno();
  Graduacao *graduacao = nullptr;
  Modalidade *modalidade = nullptr;
  bool apto = false;
  handleExecution(
      [&]()
      {
        graduacao = _dataGraduacao->buscaGraduacaoAluno(aluno->getChaveAlu());
        if (graduacao)
        {
          modalidade = _dataModalidade->buscaModalidade(graduacao->getChaveMod());
          if (aluno->getNumAulas() >= graduacao->getMinAulas())
            apto = true;
        }
        std::string nomeGrd = graduacao ? graduacao->getNome() : "-";
        std::string nomeMod = modalidade ? modalidade->getNome() : "-";

        std::cout
            << "DADOS DO USUÁRIO" << std::endl;
        std::cout << "CHAVE ALUNO: " << aluno->getChaveAlu() << std::endl;
        std::cout << "CHAVE USUÁRIO: " << aluno->getChaveUsu() << std::endl;
        std::cout << "NOME: " << aluno->getNome() << std::endl;
        std::cout << "MODALIDADE: " << nomeMod << std::endl;
        std::cout << "GRADUAÇÃO: " << nomeGrd << std::endl;
        std::cout << "Nº DE AULAS NA GRADUAÇÃO: " << aluno->getNumAulas() << std::endl;
        std::cout << "APTO A GRADUAR: " << (apto ? "SIM" : "NÃO") << std::endl;
        std::cout << "APELIDO: " << aluno->getApelido() << std::endl;
        std::cout << "DATA DE NASC.: " << aluno->getDtNascimento() << std::endl;
        std::cout << "CPF: " << aluno->getCpf() << std::endl;
        std::cout << "SEXO: " << (aluno->getSexo() == 'M' ? "Masculino" : "Feminino") << std::endl;
        std::cout << "LOGIN: " << aluno->getLogin() << std::endl;
        hold();
      });
  if (graduacao)
    delete graduacao;
  if (modalidade)
    delete modalidade;
  return RetornoController::Completo;
}

RetornoController ControllerAcessoAluno::graduacao()
{
  Aluno *aluno = _session->getSelectedAluno();
  Graduacao *graduacao = nullptr;
  char escolha;
  handleExecution(
      [&]()
      {
        graduacao = _dataGraduacao->buscaGraduacaoAluno(aluno->getChaveAlu());
        if (!graduacao)
        {
          std::cout << "Graduação não pôde ser encontrada!" << std::endl;
          return;
        }
        if (aluno->getNumAulas() < graduacao->getMinAulas())
        {
          std::cout << "De acordo com o número de aulas, o aluno não está apto a graduar." << std::endl;
          std::cout << "Deseja realizar a graduação mesmo assim (S/N)?" << std::endl;
          std::cout << "Sua escolha: ";
          escolha = readVal<char>(
              [&](char val)
              {
                val = std::tolower(val);
                if (val != 's' && val != 'n')
                {
                  std::cout << "Opção inválida!" << std::endl;
                  return false;
                }
                return true;
              });
          escolha = std::tolower(escolha);
          if (escolha == 'n')
            return;
        }
        std::vector<Graduacao> listaGraduacao = _dataGraduacao->buscaGraduacoesSeguintes(graduacao);
        if (!listaGraduacao.size())
        {
          std::cout << "Não há mais graduações!" << std::endl;
          return;
        }
        std::cout << "GRADUAÇÃO DO ALUNO" << std::endl;
        std::cout << "Graduação atual: " << graduacao->getNome() << std::endl;
        std::cout << "Nº de aulas: " << aluno->getNumAulas() << "/" << graduacao->getMinAulas() << std::endl;
        std::cout << "Escolha a nova graduação: " << std::endl;
        bool primeira = true;
        for (int i = 0; i < listaGraduacao.size(); i++)
        {
          std::cout << i + 1 << " - " << listaGraduacao[i].getNome();
          if (primeira)
          {
            primeira = false;
            std::cout << " [RECOMENDADA]";
          }
          std::cout << std::endl;
        }
        std::cout << listaGraduacao.size() + 1 << " - Cancelar" << std::endl;
        std::cout << "Sua escolha: ";
        int index = readVal<int>(
            [&](int val)
            {
              if (val < 1 || val > listaGraduacao.size() + 1)
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            });
        if (index == listaGraduacao.size() + 1)
          return;
        index--;
        std::cout << "Deseja confirmar a passagem do aluno \"" << aluno->getNome() << "\" para a graduação \"" << listaGraduacao[index].getNome() << "\" (S/N)?" << std::endl;
        std::cout << "O processo é >>irreversível<<!" << std::endl;
        std::cout << "Sua escolha: ";
        escolha = readVal<char>(
            [&](char val)
            {
              val = std::tolower(val);
              if (val != 's' && val != 'n')
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            });
        escolha = std::tolower(escolha);
        if (escolha == 'n')
          return;
        _dataAluno->realizaGraduacao(aluno->getChaveAlu(), listaGraduacao[index].getChaveGrd());
        aluno->setNumAulas(0);
        std::cout << "Graduação realizada com sucesso!" << std::endl;
      });
  if (graduacao)
    delete graduacao;
  return RetornoController::Completo;
}