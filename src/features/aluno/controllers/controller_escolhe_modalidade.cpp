#include "controller_escolhe_modalidade.h"
#include <vector>

ControllerEscolheModalidade::ControllerEscolheModalidade(Session *session, DataModalidade *dataModalidade, MenuAluno *menuAluno) : _session(session), _dataModalidade(dataModalidade), _menuAluno(menuAluno) {}

RetornoController ControllerEscolheModalidade::entraMenuAlunos()
{
  return handleExecution(
      [&]()
      {
        std::vector<Modalidade> listaModalidade = _dataModalidade->buscaListaModalidade();
        if (!listaModalidade.size())
        {
          std::cout << "Sem modalidades cadastradas!" << std::endl;
          return;
        }
        std::cout << "Selecione a modalidade: " << std::endl;
        for (int i = 0; i < listaModalidade.size(); i++)
        {
          std::cout << i + 1 << " - " << listaModalidade[i].getNome() << std::endl;
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
        _session->setSelectedModalidade(listaModalidade[modalidade]);
        finalizarTela();
        _menuAluno->executar();
      });
}