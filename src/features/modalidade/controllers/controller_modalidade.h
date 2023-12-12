#ifndef INF112_CONTROLLER_MODALIDADE_H
#define INF112_CONTROLLER_MODALIDADE_H
#include "controller.h"
#include "global.h"
#include "session.h"
#include "data_modalidade.h"

// Classe responsável por controlar as operações de modalidade
class ControllerModalidade: public Controller
{
private:
    Session *_session;
    DataModalidade *_dataModalidade;

public:
    ControllerModalidade(Session *session, DataModalidade *dataModalidade);

    // Realiza o cadastro de uma nova modalidade
    RetornoController realizaCadastro();
    // edita uma modalidade
    RetornoController realizaEdicao();
    // remove uma modalidade
    RetornoController realizaRemocao();
    // lista as modalidades
    RetornoController realizaListagem();
};

#endif