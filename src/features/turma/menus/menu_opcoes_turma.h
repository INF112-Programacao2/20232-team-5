#ifndef INF112_MENU_OPCOES_TURMA_H
#define INF112_MENU_OPCOES_TURMA_H
#include "menu.h"
#include "session.h"
#include "controller_turma.h"

class MenuOpcoesTurma : public Menu
{
protected:
    Session *_session;
    ControllerTurma *_controllerTurma;
    virtual void inicializarOpcoes();

public:
    MenuOpcoesTurma(std::string title, ControllerTurma *controllerTurma);
};

#endif
