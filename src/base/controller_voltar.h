#ifndef INF112_CONTROLLER_VOLTAR_H
#define INF112_CONTROLLER_VOLTAR_H
#include "controller.h"

class ControllerVoltar : public IController
{
public:
  virtual RetornoController executar();
};

#endif