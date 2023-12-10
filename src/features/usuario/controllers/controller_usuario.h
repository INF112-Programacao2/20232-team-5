#ifndef INF112_CONTROLLER_USUARIO_H
#define INF112_CONTROLLER_USUARIO_H
#include <functional>
#include "global.h"
#include "session.h"
#include "menu_editar_usuario.h"
#include "controller.h"
#include "controller_opcoes_usuario.h"
#include "data_usuario.h"

class ControllerUsuario : public Controller
{
private:
  Session *_session;
  MenuEditarUsuario *_menuEditarUsuario;
  ControllerOpcoesUsuario *_controllerOpcoesUsuario;
  DataUsuario *_dataUsuario;

public:
  ControllerUsuario(Session *session, DataUsuario *dataUsuario, ControllerOpcoesUsuario *controllerOpcoesUsuario, MenuEditarUsuario *menuEditarUsuario);
  RetornoController listaTodos();
  RetornoController verDados();
  RetornoController editarDados();
};

#endif