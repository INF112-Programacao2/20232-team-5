﻿#include "controller_turma.h"
#include <iostream>
#include "turma.h"

ControllerTurma::ControllerTurma(Session *session, DataTurma *dataTurma, DataUsuario *dataUsuario, DataModalidade *dataModalidade) : _session(session), _dataTurma(dataTurma), _dataUsuario(dataUsuario), _dataModalidade(dataModalidade)
{
}

RetornoController ControllerTurma::realizaCadastro()
{
    Turma *turma = nullptr;
    Usuario *usuario = nullptr;
    Modalidade *modalidade = nullptr;
    handleExecution(
        [&]()
        {
            int _chaveUsu;
            int _chaveMod;
            std::string _hrInicio;
            std::string _hrFim;
            std::string _diasSemana;

            // Solicitar valores ao usuário
            std::cout << "CADASTRO DE TURMA" << std::endl;

            std::cout << "Digite a chave do usuário (professor): ";
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

            usuario = _dataUsuario->buscaUsuarioByChave(_chaveUsu);
            if (!usuario)
            {
                std::cout << "Usuário não encontrado!" << std::endl;
                return;
            }

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

            modalidade = _dataModalidade->buscaModalidade(_chaveMod);
            if (!modalidade)
            {
                std::cout << "Modalidade não encontrada!" << std::endl;
                return;
            }

            std::cout << "Digite a hora de início: ";
            _hrInicio = readLine();

            std::cout << "Digite a hora de fim: ";
            _hrFim = readLine();

            std::cout << "Digite os dias da semana: ";
            _diasSemana = readLine();

            turma = new Turma(nullnum, _chaveUsu, _chaveMod, _hrInicio, _hrFim, _diasSemana);

            _dataTurma->cadastraTurma(turma);

            std::cout << "Turma cadastrada com sucesso!" << std::endl;
        });
    if (turma)
        delete turma;
    if (usuario)
        delete usuario;
    if (modalidade)
        delete modalidade;
    return RetornoController::Completo;
}

RetornoController ControllerTurma::realizaEdicao()
{
    Turma *turma = nullptr;
    Usuario *usuario = nullptr;
    Modalidade *modalidade = nullptr;
    handleExecution(
        [&]()
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

            turma = _dataTurma->buscaTurma(chaveTurma);
            if (!turma)
            {
                std::cout << "Turma não encontrada!" << std::endl;
                return;
            }

            std::cout
                << "Digite a chave do usuário: ";
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

            usuario = _dataUsuario->buscaUsuarioByChave(_chaveUsu);
            if (!usuario)
            {
                std::cout << "Usuário não encontrado!" << std::endl;
                return;
            }

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

            modalidade = _dataModalidade->buscaModalidade(_chaveMod);
            if (!modalidade)
            {
                std::cout << "Modalidade não encontrada!" << std::endl;
                return;
            }

            std::cout << "Digite a hora de início: ";
            _hrInicio = readLine();

            std::cout << "Digite a hora de fim: ";
            _hrFim = readLine();

            std::cout << "Digite os dias da semana: ";
            _diasSemana = readLine();

            turma = new Turma(chaveTurma, _chaveUsu, _chaveMod, _hrInicio, _hrFim, _diasSemana);

            _dataTurma->editarTurma(turma);

            std::cout << "Turma editada com sucesso!" << std::endl;
        });
    if (turma)
        delete turma;
    if (usuario)
        delete usuario;
    if (modalidade)
        delete modalidade;
    return RetornoController::Completo;
}

RetornoController ControllerTurma::realizaRemocao()
{
    Turma *turma = nullptr;
    handleExecution(
        [&]()
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

            turma = _dataTurma->buscaTurma(chaveTurma);
            if (!turma)
            {
                std::cout << "Turma não encontrada!" << std::endl;
                return;
            }

            _dataTurma->excluirTurma(chaveTurma);

            std::cout << "Turma excluída com sucesso!" << std::endl;
        });
    if (turma)
        delete turma;
    return RetornoController::Completo;
}

RetornoController ControllerTurma::realizaListagem()
{
    return handleExecution(
        [&]()
        {
            _dataTurma->listarTurmas();
            hold();
        });
}

RetornoController ControllerTurma::realizaPresenca()
{
    Turma *turma = nullptr;
    handleExecution(
        [&]()
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

            turma = _dataTurma->buscaTurma(chaveTurma);
            if (!turma)
            {
                std::cout << "Turma não encontrada!" << std::endl;
                return;
            }

            _dataTurma->presencaTurma(chaveTurma);
        });
    if (turma)
        delete turma;
    return RetornoController::Completo;
}
