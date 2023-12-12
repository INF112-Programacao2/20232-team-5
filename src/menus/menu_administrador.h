#ifndef INF112_MENU_ADMINISTRADOR_H
#define INF112_MENU_ADMINISTRADOR_H
#include "menu.h"
#include "global.h"
#include "session.h"
#include "menu_opcoes_usuario.h"
#include "menu_cadastro_pendente.h"
#include "menu_cadastros.h"
#include "controller_escolhe_modalidade.h"

class MenuAdministrador : public Menu
{
protected:
  Session *_session;
  MenuOpcoesUsuario *_menuOpcoesUsuario;
  MenuCadastroPendente *_menuCadastroPendente;
  MenuCadastros *_menuCadastros;
  ControllerEscolheModalidade *_controllerEscolheModalidade;
  virtual void inicializarOpcoes();

public:
  MenuAdministrador(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario, MenuCadastroPendente *menuCadastroPendente, MenuCadastros *menuCadastros, ControllerEscolheModalidade *controllerEscolheModalidade);
};

#endif