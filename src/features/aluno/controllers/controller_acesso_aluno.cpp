#include "controller_acesso_aluno.h"
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
  handleExecution(
      [&]() {

      });
}