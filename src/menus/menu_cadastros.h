#ifndef INF112_MENU_CADASTROS_H
#define INF112_MENU_CADASTROS_H
#include "menu.h"
#include "session.h"
#include "menu_opcoes_graduacao.h"
#include "menu_opcoes_turma.h"

class MenuCadastros : public Menu
{
protected:
    Session *_session;
    MenuOpcoesGraduacao *_menuOpcoesGraduacao;
    MenuOpcoesTurma *_menuOpcoesTurma;
    virtual void inicializarOpcoes();

public:
    MenuCadastros(std::string title, Session *session, MenuOpcoesGraduacao *menuOpcoesGraduacao, MenuOpcoesTurma *menuOpcoesTurma);
};

#endif
