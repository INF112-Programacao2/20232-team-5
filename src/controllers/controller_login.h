#ifndef INF112_CONTROLLER_LOGIN_H
#define INF112_CONTROLLER_LOGIN_H
#include <iostream>
#include <string>
#include "global.h"
#include "controller.h"

class ControllerLogin : public IController
{
public:
  virtual RetornoController executar();
};

#endif