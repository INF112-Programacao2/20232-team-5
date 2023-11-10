#ifndef INF112_CONTROLLER_H
#define INF112_CONTROLLER_H
#include "global.h"

class IController
{
public:
  virtual RetornoController executar() = 0;
};

#endif