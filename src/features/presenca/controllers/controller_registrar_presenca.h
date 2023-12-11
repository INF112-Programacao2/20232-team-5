#ifndef INF112_CONTROLLER_REGISTRAR_PRESENCA_H
#define INF112_CONTROLLER_REGISTRAR_PRESENCA_H
#include "global.h"
#include "session.h"
#include "controller.h"
#include "data_presenca.h"
#include "data_modalidade.h"
#include "data_usuario.h"
#include "data_perfil.h"
#include "data_turma.h"
#include <vector>

// Classe responsável por controlar as presenças dos alunos

class ControllerRegistrarPresenca : public Controller
{
private:
  Session *_session;
  DataPresenca *_dataPresenca;
  DataModalidade *_dataModalidade;
  DataUsuario *_dataUsuario;
  DataPerfil *_dataPerfil;
  DataTurma *_dataTurma;

  std::vector<Turma*> ListarTurmasUsuario(int idUsuario);
  std::vector<Turma*> ListarTurmasUsuarioLogado();

public:
    ControllerRegistrarPresenca(Session *session, DataPresenca *dataPresenca, DataModalidade *dataModalidade, DataUsuario *dataUsuario, DataPerfil *dataPerfil, DataTurma *dataTurma);
    RetornoController registrarPresencaUsuarioLogado();
};

#endif