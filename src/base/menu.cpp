#include <iostream>
#include "menu.h"

Menu::Menu(std::string title) : _title(title)
{
}

RetornoController Menu::executar()
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
    else if (retorno == RetornoController::Logout)
      return RetornoController::Logout;
    finalizarTela();
  }
  return RetornoController::Completo;
}

void Menu::exibir()
{
  std::cout << _title << std::endl;
  for (int i = 0; i < _opcaoList.size(); i++)
    std::cout << i + 1 << " - " << _opcaoList[i].getLabel() << std::endl;
  std::cout << "Sua escolha: ";
}