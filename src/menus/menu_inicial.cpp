#include "menu_inicial.h"
#include "opcao_menu.h"

MenuInicial::MenuInicial(std::string title, ControllerAutenticacao *controllerAutenticacao) : Menu(title), _controllerAutenticacao(controllerAutenticacao)
{
  inicializarOpcoes();
}

void MenuInicial::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Cadastro", std::bind(&ControllerAutenticacao::realizaCadastro, _controllerAutenticacao)));
  _opcaoList.push_back(OpcaoMenu("Login", std::bind(&ControllerAutenticacao::realizaLogin, _controllerAutenticacao)));
  _opcaoList.push_back(OpcaoMenu("Sair", std::bind(sair)));
}

RetornoController MenuInicial::executar()
{

  int escolha, retorno;
  while (true)
  {
    exibir();
    escolha = readVal<int>(
        [&](int val)
        {
          if (val < 1 || val > _opcaoList.size())
          {
            std::cout << "Opção inválida!" << std::endl;
            return false;
          }
          return true;
        });
    escolha--;
    finalizarTela();
    retorno = _opcaoList[escolha].executar();
    if (retorno == RetornoController::Voltar)
      break;
    else if (retorno == RetornoController::Sair)
      return RetornoController::Sair;
    finalizarTela();
  }
  return RetornoController::Completo;
}