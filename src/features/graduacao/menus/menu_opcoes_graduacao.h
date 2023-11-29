#ifndef INF112_MENU_OPCOES_GRADUACAO_H
#define INF112_MENU_OPCOES_GRADUACAO_H
#include "menu.h"
#include "session.h"
#include "controller_graduacao.h"

class MenuOpcoesGraduacao : public Menu
{
protected:
    Session *_session;
    ControllerGraduacao *_controllerGraduacao;
    virtual void inicializarOpcoes();

public:
    MenuOpcoesGraduacao(std::string title, ControllerGraduacao *controllerGraduacao);
};

#endif