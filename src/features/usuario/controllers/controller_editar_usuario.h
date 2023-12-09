#ifndef INF112_CONTROLLER_EDITAR_USUARIO_H
#define INF112_CONTROLLER_EDITAR_USUARIO_H
#include "data_usuario.h"
#include "global.h"
#include "session.h"
#include "controller.h"
#include <functional>

class ControllerEditarUsuario : public Controller
{
private:
  Session *_session;
  DataUsuario *_dataUsuario;

public:
  ControllerEditarUsuario(Session *session, DataUsuario *dataUsuario);
  RetornoController editarNome();
  RetornoController editarApelido();
  RetornoController editarDtNascimento();
  RetornoController editarCpf();
  RetornoController editarSexo();
  RetornoController editarLogin();
};

#endif