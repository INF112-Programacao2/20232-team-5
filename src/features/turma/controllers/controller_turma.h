#ifndef INF112_CONTROLLER_TURMA_H
#define INF112_CONTROLLER_TURMA_H

#include "global.h"
#include "session.h"
#include "data_turma.h"

// Classe responsável por controlar as operações de turma
class ControllerTurma
{
private:
    Session *_session;
    DataTurma *_dataTurma;

public:
    ControllerTurma(Session *session, DataTurma *dataTurma);

    // Realiza o cadastro de uma nova turma
    RetornoController realizaCadastro();
    // edita uma turma
    RetornoController realizaEdicao();
    // remove uma turma
    RetornoController realizaRemocao();
    // lista as turmas
    RetornoController realizaListagem();
    // lista as turmas
    RetornoController realizaPresenca();
};

#endif
