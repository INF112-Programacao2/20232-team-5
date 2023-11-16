#include <iostream>
#include "menu.h"

Menu::Menu(std::string title) : _title(title)
{
}

RetornoController Menu::executar()
{
  int retorno;
  while (true)
  {
    exibir();
    int escolha;
    while (true)
    {
      std::cin >> escolha;
      if (escolha > 0 && escolha <= _opcaoList.size())
        break;
      else
        std::cout << "Escolha inválida!\nInsira novamente: ";
    }
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

void Menu::exibir()
{
  std::cout << _title << std::endl;
  for (int i = 0; i < _opcaoList.size(); i++)
    std::cout << i + 1 << " - " << _opcaoList[i].getLabel() << std::endl;
  std::cout << "Escolha: " << std::endl;
}