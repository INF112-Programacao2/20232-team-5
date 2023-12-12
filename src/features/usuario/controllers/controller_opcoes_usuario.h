#ifndef INF112_CONTROLLER_OPCOES_USUARIO_H
#define INF112_CONTROLLER_OPCOES_USUARIO_H
#include "global.h"
#include "session.h"
#include <vector>
#include "controller.h"
#include "data_usuario.h"
#include "data_modalidade.h"
#include "data_autenticacao.h"
#include "data_perfil.h"

// Classe responsável por controlar as operações de autenticação

class ControllerOpcoesUsuario : public Controller
{
private:
  Session *_session;
  DataUsuario *_dataUsuario;
  DataModalidade *_dataModalidade;
  DataAutenticacao *_dataAutenticacao;
  DataPerfil *_dataPerfil;

  int escolhaPerfil();
  std::string getTipoStr(TipoPerfil tipo);

public:
  ControllerOpcoesUsuario(Session *session, DataUsuario *dataUsuario, DataModalidade *dataModalidade, DataAutenticacao *dataAutenticacao, DataPerfil *dataPerfil);
  RetornoController alternaPerfil();
  RetornoController trocaSenha();
  RetornoController verDados();
  RetornoController novoCadastro();
};

#endif