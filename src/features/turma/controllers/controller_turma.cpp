#include "controller_turma.h"
#include <iostream>
#include "turma.h"

ControllerTurma::ControllerTurma(Session *session, DataTurma *dataTurma)
    : _session(session), _dataTurma(dataTurma)
{
}

/*RetornoController ControllerTurma::realizaCadastro()
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

    return RetornoController::Completo;
}*/

RetornoController ControllerTurma::realizaCadastro()
{
    std::string hrInicio;
    std::string hrFim;
    std::string diasSemana;

    // Solicitar valores ao usuário
    std::cout << "CADASTRO DE TURMA" << std::endl;

    std::cout << "Digite a hora de início: ";
    hrInicio = readLine();

    std::cout << "Digite a hora de fim: ";
    hrFim = readLine();

    std::cout << "Digite os dias da semana: ";
    diasSemana = readLine();

    Turma *turma = new Turma(0, 0, 0, hrInicio, hrFim, diasSemana);

    _dataTurma->cadastraTurma(turma);

    return RetornoController::Completo;

}