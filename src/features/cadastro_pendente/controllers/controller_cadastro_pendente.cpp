#include "controller_cadastro_pendente.h"
#include <vector>
#include "cad_pendente.h"

ControllerCadastroPendente::ControllerCadastroPendente(Session *session) : _session(session) {}

RetornoController ControllerCadastroPendente::listaTodos()
{
  // std::vector<CadPendente> listaCadPendente = _data
  return RetornoController::Completo;
}