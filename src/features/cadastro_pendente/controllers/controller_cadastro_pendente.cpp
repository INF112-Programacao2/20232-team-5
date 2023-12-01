#include "controller_cadastro_pendente.h"
#include <vector>
#include "cad_pendente.h"

ControllerCadastroPendente::ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente) : _session(session), _dataCadastroPendente(dataCadastroPendente) {}

RetornoController ControllerCadastroPendente::listaTodos()
{
  _dataCadastroPendente->buscaListaCadastroPendente();
  return RetornoController::Completo;
}