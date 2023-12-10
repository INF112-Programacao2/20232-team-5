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

    int _chaveUsu;
    int _chaveMod;
    std::string _hrInicio;
    std::string _hrFim;
    std::string _diasSemana;

    // Solicitar valores ao usuário
    std::cout << "CADASTRO DE TURMA" << std::endl;

    std::cout << "Digite a chave do usuário: ";
    _chaveUsu = readVal<int>(
        [&](int _chaveUsu)
        {
            if (_chaveUsu < 0)
            {
                std::cout << "Opção inválida!" << std::endl;
                return false;
            }
            return true;
        });

    std::cout << "Digite a chave da modalidade: ";
    _chaveMod = readVal<int>(
        [&](int _chaveMod)
        {
            if (_chaveMod < 0)
            {
                std::cout << "Opção inválida!" << std::endl;
                return false;
            }
            return true;
        });

    std::cout << "Digite a hora de início: ";
    _hrInicio = readLine();

    std::cout << "Digite a hora de fim: ";
    _hrFim = readLine();

    std::cout << "Digite os dias da semana: ";
    _diasSemana = readLine();

    Turma *turma = new Turma(nullnum, _chaveUsu, _chaveMod, _hrInicio, _hrFim, _diasSemana);

    _dataTurma->cadastraTurma(turma);

    return RetornoController::Completo;
}

RetornoController ControllerTurma::realizaEdicao()
{
    int chaveTurma;
    int _chaveUsu;
    int _chaveMod;
    std::string _hrInicio;
    std::string _hrFim;
    std::string _diasSemana;

    // Solicitar valores ao usuário
    std::cout << "EDIÇÃO DE TURMA" << std::endl;

    std::cout << "Digite a chave da turma: ";
    chaveTurma = readVal<int>(
        [&](int chaveTurma)
        {
            if (chaveTurma < 0)
            {
                std::cout << "Opção inválida!" << std::endl;
                return false;
            }
            return true;
        });

    std::cout << "Digite a chave do usuário: ";
    _chaveUsu = readVal<int>(
        [&](int _chaveUsu)
        {
            if (_chaveUsu < 0)
            {
                std::cout << "Opção inválida!" << std::endl;
                return false;
            }
            return true;
        });

    std::cout << "Digite a chave da modalidade: ";
    _chaveMod = readVal<int>(
        [&](int _chaveMod)
        {
            if (_chaveMod < 0)
            {
                std::cout << "Opção inválida!" << std::endl;
                return false;
            }
            return true;
        });

    std::cout << "Digite a hora de início: ";
    _hrInicio = readLine();

    std::cout << "Digite a hora de fim: ";
    _hrFim = readLine();

    std::cout << "Digite os dias da semana: ";
    _diasSemana = readLine();

    Turma *turma = new Turma(chaveTurma, _chaveUsu, _chaveMod, _hrInicio, _hrFim, _diasSemana);

    _dataTurma->editarTurma(turma);

    return RetornoController::Completo;
}

RetornoController ControllerTurma::realizaRemocao()
{
    int chaveTurma;

    // Solicitar valores ao usuário
    std::cout << "EXCLUSÃO DE TURMA" << std::endl;

    std::cout << "Digite a chave da turma: ";
    chaveTurma = readVal<int>(
        [&](int chaveTurma)
        {
            if (chaveTurma < 0)
            {
                std::cout << "Opção inválida!" << std::endl;
                return false;
            }
            return true;
        });

    _dataTurma->excluirTurma(chaveTurma);

    return RetornoController::Completo;
}

RetornoController ControllerTurma::realizaListagem()
{
    _dataTurma->listarTurmas();

    return RetornoController::Completo;
}

RetornoController ControllerTurma::realizaPresenca()
{
    int chaveTurma;

    // Solicitar valores ao usuário
    std::cout << "LISTAGEM DE PRESENÇA" << std::endl;

    std::cout << "Digite a chave da turma: ";
    chaveTurma = readVal<int>(
        [&](int chaveTurma)
        {
            if (chaveTurma < 0)
            {
                std::cout << "Opção inválida!" << std::endl;
                return false;
            }
            return true;
        });

    _dataTurma->presencaTurma(chaveTurma);

    return RetornoController::Completo;
}
