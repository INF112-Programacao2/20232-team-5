#ifndef INF112_CONTROLLER_MODALIDADE_H
#define INF112_CONTROLLER_MODALIDADE_H

#include "global.h"
#include "session.h"
#include "data_modalidade.h"

// Classe responsável por controlar as operações de modalidade
class ControllerModalidade
{
private:
    Session *_session;
    DataModalidade *_dataModalidade;

public:

    ControllerModalidade(Session *session, DataModalidade *dataModalidade);

    // Realiza o cadastro de uma nova modalidade
    RetornoController realizaCadastro();
};

#endif