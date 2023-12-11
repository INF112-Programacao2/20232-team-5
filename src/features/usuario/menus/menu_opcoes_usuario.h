#ifndef INF112_MENU_OPCOES_USUARIO_H
#define INF112_MENU_OPCOES_USUARIO_H
#include "global.h"
#include "menu.h"
#include "session.h"
#include "controller_opcoes_usuario.h"
#include "menu_editar_usuario.h"
#include "controller_registrar_presenca.h"

class MenuOpcoesUsuario : public Menu
{
protected:
  Session *_session;
  ControllerOpcoesUsuario *_controllerOpcoesUsuario;
  MenuEditarUsuario *_menuEditarUsuario;
  ControllerRegistrarPresenca *_controllerRegistrarPresenca;
  
  virtual void inicializarOpcoes();

public:
  MenuOpcoesUsuario(std::string title, Session *_session, ControllerOpcoesUsuario *controllerOpcoesUsuario, MenuEditarUsuario *menuEditarUsuario, ControllerRegistrarPresenca *controllerRegistrarPresenca);
  RetornoController executar() override;
};

#endif