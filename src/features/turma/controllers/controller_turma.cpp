#include "controller_turma.h"
#include <iostream>
#include "turma.h"

ControllerTurma::ControllerTurma(Session *session, DataTurma *dataTurma)
    : _session(session), _dataTurma(dataTurma)
{
}

RetornoController ControllerTurma::realizaCadastro()
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

    // Cria a turma
    Turma *turma = new Turma(0, nome, ordem, minAulas);

    // Salva a turma
    _dataTurma->cadastraTurma(turma);

    return RetornoController::Completo;
}
