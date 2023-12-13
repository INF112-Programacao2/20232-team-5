#include "controller_modalidade.h"
#include <iostream>
#include "modalidade.h"
#include "global.h"

ControllerModalidade::ControllerModalidade(Session *session, DataModalidade *dataModalidade) : _session(session), _dataModalidade(dataModalidade)
{
}

RetornoController ControllerModalidade::realizaCadastro()
{
    Modalidade *modalidade = nullptr;
    handleExecution(
        [&]()
        {
            std::string nome;

            // Solicitar valores ao usuário
            std::cout << "CADASTRO" << std::endl;

            std::cout << "Digite o nome: ";
            nome = readLine();

            // Cria a modalidade
            modalidade = new Modalidade(nullnum, nome);

            // salva a modalidade
            _dataModalidade->cadastraModalidade(modalidade);
            std::cout << "Modalidade cadastrada com sucesso!" << std::endl;
        });
    if (modalidade)
        delete modalidade;
    return RetornoController::Completo;
}

RetornoController ControllerModalidade::realizaEdicao()
{
    Modalidade *modalidade = nullptr;
    handleExecution(
        [&]()
        {
            std::string nome;
            int chaveMod;

            // Solicitar valores ao usuário
            std::cout << "EDIÇÃO" << std::endl;

            std::cout << "Informe a chave da modalidade: ";
            chaveMod = readVal<int>(
                [&](int chaveMod)
                {
                    if (chaveMod < 0)
                    {
                        std::cout << "Opção inválida!" << std::endl;
                        return false;
                    }
                    return true;
                });

            // Verifica se modalidade existe
            modalidade = _dataModalidade->buscaModalidade(chaveMod);
            if (!modalidade)
            {
                std::cout << "Modalidade não encontrada!" << std::endl;
                return;
            }

            std::cout << "Digite o nome: ";
            nome = readLine();

            // salva a modalidade
            _dataModalidade->editaModalidade(chaveMod, nome);
            std::cout << "Modalidade editada com sucesso!" << std::endl;
        });
    if (modalidade)
        delete modalidade;
    return RetornoController::Completo;
}

RetornoController ControllerModalidade::realizaRemocao()
{
    Modalidade *modalidade = nullptr;
    handleExecution(
        [&]()
        {
            std::string nome;
            int chaveMod;

            // Solicitar valores ao usuário
            std::cout << "REMOÇÃO" << std::endl;

            std::cout << "Informe a chave da modalidade: ";
            chaveMod = readVal<int>(
                [&](int chaveMod)
                {
                    if (chaveMod < 0)
                    {
                        std::cout << "Opção inválida!" << std::endl;
                        return false;
                    }
                    return true;
                });

            // Verifica se modalidade existe
            modalidade = _dataModalidade->buscaModalidade(chaveMod);
            if (!modalidade)
            {
                std::cout << "Modalidade não encontrada!" << std::endl;
                return;
            }

            // exclui a modalidade
            _dataModalidade->excluiModalidade(chaveMod);
            std::cout << "Modalidade deletada com sucesso!" << std::endl;
        });
    if (modalidade)
        delete modalidade;
    return RetornoController::Completo;
}

RetornoController ControllerModalidade::realizaListagem()
{
    return handleExecution(
        [&]()
        {
            std::vector<Modalidade> listaModalidade = _dataModalidade->buscaListaModalidade();

            std::cout << "LISTAGEM" << std::endl;

            for (Modalidade modalidade : listaModalidade)
            {
                std::cout << "Chave: " << modalidade.getChaveMod() << std::endl;
                std::cout << "Nome: " << modalidade.getNome() << std::endl;
            }
            hold();
        });
}