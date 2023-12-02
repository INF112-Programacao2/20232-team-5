#include "controller_cadastro_pendente.h"
#include <vector>
#include "modalidade.h"
#include "cad_pendente.h"

ControllerCadastroPendente::ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente, DataUsuario *dataUsuario, DataModalidade *dataModalidade) : _session(session), _dataCadastroPendente(dataCadastroPendente), _dataUsuario(dataUsuario), _dataModalidade(dataModalidade) {}

RetornoController ControllerCadastroPendente::listaTodos()
{
  std::vector<CadPendente> listaCadPendente = _dataCadastroPendente->buscaListaCadastroPendente();
  std::vector<Modalidade> listaModalidade = _dataModalidade->buscaListaModalidade();
  std::string tipo;
  for (auto cadPendente : listaCadPendente)
  {
    if (cadPendente.getTipoCadastro() == TipoCadastro::Interno)
    {
      Usuario *usuario = _dataUsuario->buscaUsuarioByChave(cadPendente.getChaveUsu());
      cadPendente.setFromUsuario(usuario);
      delete usuario;
    }
    if (cadPendente.getTipo() == 'C')
      tipo = "Cliente";
    else if (cadPendente.getTipo() == 'P')
      tipo = "Professor";
    else
      tipo = "Administrador";
    std::cout << "CHAVE: " << cadPendente.getChaveCad() << " | NOME: " << cadPendente.getNome() << " | TIPO: " << tipo;
    // Procura a modalidade para printar o nome, caso seja cliente
    if (cadPendente.getTipo() == 'C')
    {
      for (auto modalidade : listaModalidade)
        if (modalidade.getChaveMod() == cadPendente.getChaveMod())
          std::cout << " | MODALIDADE: " << modalidade.getNome() << std::endl;
    }
    else
      std::cout << std::endl;
  }
  hold();
  return RetornoController::Completo;
}