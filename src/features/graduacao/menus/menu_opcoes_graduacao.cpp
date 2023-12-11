#include "menu_opcoes_graduacao.h"
#include "opcao_menu.h"
#include "global.h"
#include "controller_graduacao.h"

MenuOpcoesGraduacao::MenuOpcoesGraduacao(std::string title, ControllerGraduacao *controllerGraduacao) : Menu(title), _controllerGraduacao(controllerGraduacao)
{
  inicializarOpcoes();
}

void MenuOpcoesGraduacao::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Cadastrar graduacao", std::bind(&ControllerGraduacao::realizaCadastro, _controllerGraduacao)));
  _opcaoList.push_back(OpcaoMenu("Editar graduacao", std::bind(&ControllerGraduacao::realizaEdicao, _controllerGraduacao)));
  _opcaoList.push_back(OpcaoMenu("Excluir graduacao", std::bind(&ControllerGraduacao::realizaRemocao, _controllerGraduacao)));
  _opcaoList.push_back(OpcaoMenu("Listar graduacao", std::bind(&ControllerGraduacao::realizaListagem, _controllerGraduacao)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}
