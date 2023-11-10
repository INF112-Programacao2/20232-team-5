#ifndef INF112_CONTROLLERSAIR_H
#define INF112_CONTROLLERSAIR_H
#include "controller.h"

class ControllerSair : public IController
{
public:
  virtual RetornoController executar();
};

#endif