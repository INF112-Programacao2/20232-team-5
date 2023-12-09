#ifndef INF112_CONTROLLER_OPCOES_USUARIO_H
#define INF112_CONTROLLER_OPCOES_USUARIO_H
#include "global.h"
#include "session.h"
#include <vector>
#include "controller.h"
#include "data_usuario.h"

// Classe responsável por controlar as operações de autenticação

class ControllerOpcoesUsuario : public Controller
{
private:
  Session *_session;
  DataUsuario *_dataUsuario;
  int escolhaPerfil();
  std::string getTipoStr(TipoPerfil tipo);

public:
  ControllerOpcoesUsuario(Session *session, DataUsuario *dataUsuario);
  RetornoController alternaPerfil();
  RetornoController trocaSenha();
  RetornoController verDados();
  RetornoController novoCadastro();
};

#endif