#ifndef INF112_MENU_OPCOES_USUARIO_H
#define INF112_MENU_OPCOES_USUARIO_H
#include "menu.h"
#include "session.h"
class ControllerAutenticacao;

class MenuOpcoesUsuario : public Menu
{
protected:
  Session *_session;
  ControllerAutenticacao *_controllerAutenticacao;
  virtual void inicializarOpcoes();

public:
  MenuOpcoesUsuario(std::string title, ControllerAutenticacao *controllerAutenticacao);
};

#endif