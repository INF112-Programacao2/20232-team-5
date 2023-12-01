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
  /*_opcaoList.push_back(OpcaoMenu("Listar graduacoes", std::bind(&ControllerGraduacao::, _controllerGraduacao)));*/
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}
