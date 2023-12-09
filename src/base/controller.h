#ifndef INF112_CONTROLLER_H
#define INF112_CONTROLLER_H
#include "global.h"

class Controller
{
protected:
  RetornoController handleExecution(std::function<void()> func);

public:
  Controller();
};

#endif