#ifndef INF112_CONTROLLER_CADASTRO_PENDENTE_H
#define INF112_CONTROLLER_CADASTRO_PENDENTE_H
#include "global.h"
#include "session.h"
#include "data_cadastro_pendente.h"
#include "data_usuario.h"
#include "data_modalidade.h"
#include <vector>
#include "modalidade.h"

class ControllerCadastroPendente
{
private:
  Session *_session;
  DataCadastroPendente *_dataCadastroPendente;
  DataUsuario *_dataUsuario;
  DataModalidade *_dataModalidade;
  void completaDados(CadPendente *cad);
  std::string getTipoStr(CadPendente *cad);
  std::string getNomeCategoria(CadPendente *cad, std::vector<Modalidade> listaModalidade);

public:
  ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente, DataUsuario *dataUsuario, DataModalidade *dataModalidade);
  RetornoController listaTodos();
  RetornoController verDetalhes();
  RetornoController rejeitaCadastro();
  RetornoController aprovaCadastro();
};

#endif