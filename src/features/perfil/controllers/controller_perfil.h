#ifndef INF112_CONTROLLER_PERFIL_H
#define INF112_CONTROLLER_PERFIL_H
#include <string>
#include "global.h"
#include "controller.h"
#include "session.h"
#include "data_perfil.h"

// Classe responsável por controlar as operações de perfil
class ControllerPerfil : public Controller
{
private:
  Session *_session;
  DataPerfil *_dataPerfil;
  std::string getTipoStr(TipoPerfil tipo);

public:
  ControllerPerfil(Session *session, DataPerfil *dataPerfil);
  RetornoController listaPerfilUsuario();
  RetornoController adicionaPerfilUsuario();
  RetornoController deletaPerfilUsuario();
};

#endif