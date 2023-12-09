#include "controller.h"
#include "database_error.h"

Controller::Controller()
{
}

RetornoController Controller::handleExecution(std::function<void()> func)
{
  try
  {
    func();
  }
  catch (DatabaseError &e)
  {
    std::cout << "Erro no banco!" << std::endl;
    std::cout << e.what() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Ocorreu um erro inesperado!" << std::endl;
    std::cout << e.what() << std::endl;
  }
  return RetornoController::Completo;
}
