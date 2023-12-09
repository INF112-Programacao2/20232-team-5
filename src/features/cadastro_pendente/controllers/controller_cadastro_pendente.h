#ifndef INF112_CONTROLLER_CADASTRO_PENDENTE_H
#define INF112_CONTROLLER_CADASTRO_PENDENTE_H
#include "global.h"
#include "session.h"
#include "data_cadastro_pendente.h"
#include "data_usuario.h"
#include "data_modalidade.h"
#include "data_autenticacao.h"
#include "data_graduacao.h"
#include "data_aluno.h"
#include <vector>
#include "modalidade.h"
#include "controller.h"

class ControllerCadastroPendente : public Controller
{
private:
  Session *_session;
  DataCadastroPendente *_dataCadastroPendente;
  DataUsuario *_dataUsuario;
  DataModalidade *_dataModalidade;
  DataAutenticacao *_dataAutenticacao;
  DataGraduacao *_dataGraduacao;
  DataAluno *_dataAluno;
  void completaDados(CadPendente *cad);
  std::string getTipoStr(CadPendente *cad);
  std::string getNomeCategoria(CadPendente *cad, std::vector<Modalidade> listaModalidade);

public:
  ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente, DataUsuario *dataUsuario, DataModalidade *dataModalidade, DataAutenticacao *dataAutenticacao, DataGraduacao *dataGraduacao, DataAluno *dataAluno);
  RetornoController listaTodos();
  RetornoController verDetalhes();
  RetornoController rejeitaCadastro();
  RetornoController aprovaCadastro();
};

#endif