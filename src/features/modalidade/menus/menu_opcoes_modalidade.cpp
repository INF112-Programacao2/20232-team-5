#include "menu_opcoes_modalidade.h"
#include "opcao_menu.h"
#include "global.h"
#include "controller_modalidade.h"

MenuOpcoesModalidade::MenuOpcoesModalidade(std::string title, ControllerModalidade *controllerModalidade) : Menu(title), _controllerModalidade(controllerModalidade)
{
  inicializarOpcoes();
}

void MenuOpcoesModalidade::inicializarOpcoes()
{
    _opcaoList.push_back(OpcaoMenu("Cadastrar modalidade", std::bind(&ControllerModalidade::realizaCadastro, _controllerModalidade)));
    _opcaoList.push_back(OpcaoMenu("Listar modalidades", std::bind(&ControllerModalidade::realizaListagem, _controllerModalidade)));
    _opcaoList.push_back(OpcaoMenu("Remover modalidade", std::bind(&ControllerModalidade::realizaRemocao, _controllerModalidade)));
    _opcaoList.push_back(OpcaoMenu("Editar modalidade", std::bind(&ControllerModalidade::realizaEdicao, _controllerModalidade)));
    _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}

// Path: src/features/modalidade/menu/menu_opcoes_modalidade.h