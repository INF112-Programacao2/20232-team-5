#ifndef INF112_CONTROLLER_CADASTRO_PENDENTE_H
#define INF112_CONTROLLER_CADASTRO_PENDENTE_H
#include "global.h"
#include "session.h"

class ControllerCadastroPendente
{
private:
  Session *_session;

public:
  ControllerCadastroPendente(Session *session);
  RetornoController listaTodos();
};

#endif