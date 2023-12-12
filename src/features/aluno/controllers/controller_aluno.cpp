#include "controller_aluno.h"
#include <vector>
#include "aluno.h"

ControllerAluno::ControllerAluno(Session *session, DataAluno *dataAluno, DataGraduacao *dataGraduacao, MenuAcessoAluno *menuAcessoAluno) : _session(session), _dataAluno(dataAluno), _dataGraduacao(dataGraduacao), _menuAcessoAluno(menuAcessoAluno) {}

RetornoController ControllerAluno::listaTodos()
{
  Graduacao *graduacao = nullptr;
  handleExecution(
      [&]()
      {
        std::vector<Aluno> listaAluno;
        std::cout << "LISTA DE ALUNOS" << std::endl;
        listaAluno = _dataAluno->buscaListaAlunos(_session->getSelectedModalidade().getChaveMod());
        if (!listaAluno.size())
        {
          std::cout << "Lista vazia!" << std::endl;
          return;
        }
        for (auto aluno : listaAluno)
        {
          graduacao = _dataGraduacao->buscaGraduacaoAluno(aluno.getChaveAlu());
          std::cout << "CHAVE: " << aluno.getChaveAlu() << " | NOME: " << aluno.getNome() << " | GRADUAÇÃO: " << graduacao->getNome() << std::endl;
        }
        hold();
      });
  if (graduacao)
    delete graduacao;
  return RetornoController::Completo;
}

RetornoController ControllerAluno::listaAptos()
{
  Graduacao *graduacao = nullptr;
  handleExecution(
      [&]()
      {
        std::vector<Aluno> listaAluno;
        std::cout << "LISTA DE ALUNOS APTOS A GRADUAR" << std::endl;
        listaAluno = _dataAluno->buscaListaAlunosAptos(_session->getSelectedModalidade().getChaveMod());
        if (!listaAluno.size())
        {
          std::cout << "Nenhum aluno apto!" << std::endl;
          return;
        }
        for (auto aluno : listaAluno)
        {
          graduacao = _dataGraduacao->buscaGraduacaoAluno(aluno.getChaveAlu());
          std::cout << "CHAVE: " << aluno.getChaveAlu() << " | NOME: " << aluno.getNome() << " | GRADUAÇÃO: " << graduacao->getNome() << std::endl;
        }
        hold();
      });
  if (graduacao)
    delete graduacao;
  return RetornoController::Completo;
}

RetornoController ControllerAluno::acessoAluno()
{
  return handleExecution(
      [&]()
      {
        int chaveAlu;
        std::cout << "Informe a chave do aluno: ";
        chaveAlu = readVal<int>();
        Aluno *aluno = _dataAluno->buscaAluno(chaveAlu);
        if (!aluno)
        {
          std::cout << "Aluno não encontrado!" << std::endl;
          return;
        }
        std::cout << "Aluno encontrado: " << aluno->getNome() << std::endl;
        finalizarTela();
        _session->setSelectedAluno(aluno);
        _menuAcessoAluno->executar();
      });
}