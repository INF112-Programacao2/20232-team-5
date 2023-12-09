#ifndef INF112_MENU_OPCOES_MODALIDADE_H
#define INF112_MENU_OPCOES_MODALIDADE_H

#include "menu.h"
#include "session.h"
#include "controller_modalidade.h"

class MenuOpcoesModalidade : public Menu
{
protected:
    Session *_session;
    ControllerModalidade *_controllerModalidade;
    virtual void inicializarOpcoes();

public:
    MenuOpcoesModalidade(std::string title, ControllerModalidade *controllerModalidade);
};

#endif