#ifndef INF112_GRADUACAO_H
#define INF112_GRADUACAO_H

#include "global.h"
#include "session.h"

// Classe responsável por controlar as operações de graduação
class ControllerGraduacao
{
private:
    Session *_session;

public:
    ControllerGraduacao(Session *session);

    // Realiza o cadastro de uma nova graduação
    RetornoController realizaCadastro();
};


#endif
