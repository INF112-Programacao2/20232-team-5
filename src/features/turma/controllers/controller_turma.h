#ifndef INF112_CONTROLLER_TURMA_H
#define INF112_CONTROLLER_TURMA_H
#include "controller.h"
#include "global.h"
#include "session.h"
#include "data_turma.h"
#include "data_usuario.h"
#include "data_modalidade.h"

// Classe responsável por controlar as operações de turma
class ControllerTurma : public Controller
{
private:
    Session *_session;
    DataTurma *_dataTurma;
    DataUsuario *_dataUsuario;
    DataModalidade *_dataModalidade;

public:
    ControllerTurma(Session *session, DataTurma *dataTurma, DataUsuario *dataUsuario, DataModalidade *dataModalidade);

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
