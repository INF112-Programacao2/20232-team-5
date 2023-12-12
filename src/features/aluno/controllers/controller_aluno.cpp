#include "controller_aluno.h"
#include <vector>
#include "aluno.h"

ControllerAluno::ControllerAluno(Session *session, DataAluno *dataAluno, DataGraduacao *dataGraduacao) : _session(session), _dataAluno(dataAluno), _dataGraduacao(dataGraduacao) {}

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
}