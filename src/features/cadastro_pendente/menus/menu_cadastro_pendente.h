#ifndef INF112_MENU_CADASTRO_PENDENTE_H
#define INF112_MENU_CADASTRO_PENDENTE_H
#include "menu.h"
#include "controller_cadastro_pendente.h"

class MenuCadastroPendente : public Menu
{
protected:
  ControllerCadastroPendente *_controllerCadastroPendente;
  virtual void inicializarOpcoes();

public:
  MenuCadastroPendente(std::string title, ControllerCadastroPendente *controllerCadastroPendente);
};

#endif