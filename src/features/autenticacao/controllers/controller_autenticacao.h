#ifndef INF112_CONTROLLER_AUTENTICACAO_H
#define INF112_CONTROLLER_AUTENTICACAO_H
#include "global.h"
#include "session.h"
#include <vector>
#include "controller.h"
#include "data_modalidade.h"
#include "data_autenticacao.h"
#include "data_perfil.h"
#include "menu_cliente.h"
#include "menu_professor.h"
#include "menu_administrador.h"

// Classe responsável por controlar as operações de autenticação

class ControllerAutenticacao : public Controller
{
private:
  Session *_session;
  DataModalidade *_dataModalidade;
  DataAutenticacao *_dataAutenticacao;
  DataPerfil *_dataPerfil;
  MenuCliente *_menuCliente;
  MenuProfessor *_menuProfessor;
  MenuAdministrador *_menuAdministrador;
  int escolhaPerfil();
  std::string getTipoStr(TipoPerfil tipo);

public:
  ControllerAutenticacao(Session *session, DataModalidade *dataModalidade, DataAutenticacao *dataAutenticacao, MenuCliente *menuCliente, MenuProfessor *menuProfessor, MenuAdministrador *menuAdministrador, DataPerfil *dataPerfil);
  RetornoController realizaCadastro();
  RetornoController realizaLogin();
  bool checaExisteLogin(std::string login);
};

#endif