#ifndef INF112_CONTROLLER_CADASTRO_PENDENTE_H
#define INF112_CONTROLLER_CADASTRO_PENDENTE_H
#include "global.h"
#include "session.h"
#include "data_cadastro_pendente.h"

class ControllerCadastroPendente
{
private:
  Session *_session;
  DataCadastroPendente *_dataCadastroPendente;

public:
  ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente);
  RetornoController listaTodos();
};

#endif