#include "controller_modalidade.h"
#include <iostream>
#include "modalidade.h"
#include "global.h"

ControllerModalidade::ControllerModalidade(Session *session, DataModalidade *dataModalidade)
    : _session(session), _dataModalidade(dataModalidade)
{
}

RetornoController ControllerModalidade::realizaCadastro()
{
    std::string nome;
    int chaveMod;

    // Solicitar valores ao usuário
    std::cout << "CADASTRO" << std::endl;

    std::cout << "Digite a chave da modalidade: ";
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

    std::cout << "Digite o nome: ";
    nome = readLine();

    // Cria a modalidade
    Modalidade *modalidade = new Modalidade(chaveMod, nome);

    // salva a modalidade
    _dataModalidade->cadastraModalidade(modalidade);

    return RetornoController::Completo;

}

RetornoController ControllerModalidade::realizaEdicao()
{
    std::string nome;
    int chaveMod;

    // Solicitar valores ao usuário
    std::cout << "EDIÇÃO" << std::endl;

    std::cout << "Digite a chave da modalidade: ";
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

    std::cout << "Digite o nome: ";
    nome = readLine();

    // Cria a modalidade
    Modalidade *modalidade = new Modalidade(chaveMod, nome);

    // salva a modalidade
    _dataModalidade->editaModalidade(modalidade);

    return RetornoController::Completo;
}

RetornoController ControllerModalidade::realizaRemocao()
{
    std::string nome;
    int chaveMod;

    // Solicitar valores ao usuário
    std::cout << "REMOÇÃO" << std::endl;

    std::cout << "Digite a chave da modalidade: ";
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

    std::cout << "Digite o nome: ";
    nome = readLine();

    // Cria a modalidade
    Modalidade *modalidade = new Modalidade(chaveMod, nome);

    // salva a modalidade
    _dataModalidade->excluiModalidade(modalidade);

    return RetornoController::Completo;
}

RetornoController ControllerModalidade::realizaListagem()
{
    std::vector<Modalidade> listaModalidade = _dataModalidade->buscaListaModalidade();

    std::cout << "LISTAGEM" << std::endl;

    for (Modalidade modalidade : listaModalidade)
    {
        std::cout << "Chave: " << modalidade.getChaveMod() << std::endl;
        std::cout << "Nome: " << modalidade.getNome() << std::endl;
    }

    return RetornoController::Completo;
}