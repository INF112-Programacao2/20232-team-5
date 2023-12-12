#include "controller_dados_aluno.h"
#include "modalidade.h"
#include "aluno.h"
#include "graduacao.h"

ControllerDadosAluno::ControllerDadosAluno(Session *session, DataModalidade *dataModalidade, DataGraduacao *dataGraduacao, DataAluno *dataAluno) : _session(session), _dataModalidade(dataModalidade), _dataGraduacao(dataGraduacao), _dataAluno(dataAluno) {}

RetornoController ControllerDadosAluno::mostraDados()
{
  std::vector<Modalidade *> listaModalidade;
  Aluno *aluno;
  Graduacao *graduacao;
  handleExecution(
      [&]()
      {
        listaModalidade = _dataModalidade->buscaListaModalidadesUsuario(_session->getUsuario()->getChaveUsu());
        if (!listaModalidade.size())
        {
          std::cout << "Você não está cadastrado em nenhuma modalidade!" << std::endl;
          return;
        }
        std::cout << "Selecione a modalidade: " << std::endl;
        for (int i = 0; i < listaModalidade.size(); i++)
        {
          std::cout << i + 1 << " - " << listaModalidade[i]->getNome() << std::endl;
        }
        std::cout << "Sua escolha: ";
        int modalidade = readVal<int>(
            [&](int val)
            {
              if (val < 1 || val > listaModalidade.size())
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            });
        modalidade--;
        aluno = _dataAluno->buscaAlunoByUsuario(_session->getUsuario()->getChaveUsu(), listaModalidade[modalidade]->getChaveMod());
        if (!aluno)
        {
          std::cout << "Dados do aluno não localizados!" << std::endl;
        }
        graduacao = _dataGraduacao->buscaGraduacaoAluno(aluno->getChaveAlu());

        finalizarTela();
        std::cout << "DADOS DO ALUNO" << std::endl;
        std::cout << "NOME: " << aluno->getNome() << std::endl;
        std::cout << "MODALIDADE: " << listaModalidade[modalidade]->getNome() << std::endl;
        std::cout << "GRADUAÇÃO: " << graduacao->getNome() << std::endl;
        std::cout << "Nº DE AULAS NA GRADUAÇÃO: " << aluno->getNumAulas() << std::endl;
        hold();
      });
  for (auto modalidade : listaModalidade)
    delete modalidade;
  if (aluno)
    delete aluno;
  if (graduacao)
    delete graduacao;
  return RetornoController::Completo;
}