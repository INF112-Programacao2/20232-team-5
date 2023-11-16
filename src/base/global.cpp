#include "global.h"

void finalizarTela()
{
  std::cout << "---------------------------------------\n";
}

void hold()
{
  std::cin.ignore();
  std::cout << "(Pressione ENTER)" << std::endl;
  std::cin.get();
}

std::string readLine()
{
  std::string val;
  std::cin.clear();
  std::getline(std::cin >> std::ws, val);
  return val;
}

RetornoController voltar()
{
  return RetornoController::Voltar;
}

RetornoController sair()
{
  return RetornoController::Sair;
}