#ifndef INF112_CONTROLLER_GRADUACAO_H
#define INF112_CONTROLLER_GRADUACAO_H

#include "global.h"
#include "session.h"
#include "data_graduacao.h"

// Classe responsável por controlar as operações de graduação
class ControllerGraduacao
{
private:
    Session *_session;
    DataGraduacao *_dataGraduacao;

public:
    ControllerGraduacao(Session *session, DataGraduacao *dataGraduacao);

    // Realiza o cadastro de uma nova graduação
    RetornoController realizaCadastro();
};

#endif
