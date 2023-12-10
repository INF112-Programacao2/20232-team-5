#ifndef INF112_CONTROLLER_PERFIL_H
#define INF112_CONTROLLER_PERFIL_H
#include "global.h"
#include "session.h"
#include "data_perfil.h"

// Classe responsável por controlar as operações de perfil
class ControllerPerfil
{
private:
  Session *_session;
  DataPerfil *_dataPerfil;

public:
  ControllerPerfil(Session *session, DataPerfil *dataPerfil);
};

#endif