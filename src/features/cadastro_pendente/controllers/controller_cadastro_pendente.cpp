#include "controller_cadastro_pendente.h"
#include <vector>
#include "modalidade.h"
#include "cad_pendente.h"
#include "database_error.h"

ControllerCadastroPendente::ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente, DataUsuario *dataUsuario, DataModalidade *dataModalidade) : _session(session), _dataCadastroPendente(dataCadastroPendente), _dataUsuario(dataUsuario), _dataModalidade(dataModalidade) {}

// Mostra todos os cadastros pendentes
RetornoController ControllerCadastroPendente::listaTodos()
{
  try
  {
    // Recupera a lista de modalidades (pra mostrar o nome da modalidade)
    std::vector<Modalidade> listaModalidade = _dataModalidade->buscaListaModalidade();
    std::vector<CadPendente> listaCadPendente = _dataCadastroPendente->buscaListaCadastroPendente();
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
  }
  catch (DatabaseError e)
  {
    std::cout << "Erro no banco!" << std::endl;
    std::cout << e.what() << std::endl;
  }
  catch (std::exception e)
  {
    std::cout << "Ocorreu um erro inesperado!" << std::endl;
    std::cout << e.what() << std::endl;
  }
  hold();
  return RetornoController::Completo;
}