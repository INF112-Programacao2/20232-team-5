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
    std::cout << "LISTA DE CADASTROS" << std::endl;
    // Recupera a lista de modalidades (pra mostrar o nome da modalidade)
    std::vector<Modalidade> listaModalidade = _dataModalidade->buscaListaModalidade();
    std::vector<CadPendente> listaCadPendente = _dataCadastroPendente->buscaListaCadastroPendente();
    std::string tipo;

    for (auto cadPendente : listaCadPendente)
    {
      // Completa dados caso seja cadastro interno
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

      std::cout << "Código: " << cadPendente.getChaveCad() << " | Nome: " << cadPendente.getNome() << " | Tipo: " << tipo;
      // Procura a modalidade para printar o nome, caso seja cliente
      if (cadPendente.getTipo() == 'C')
      {
        for (auto modalidade : listaModalidade)
          if (modalidade.getChaveMod() == cadPendente.getChaveMod())
            std::cout << " | Modalidade: " << modalidade.getNome();
      }

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

RetornoController ControllerCadastroPendente::verDetalhes()
{
  try
  {
    int chaveCad;
    std::cout << "Informe a chave do cadastro: ";
    chaveCad = readVal<int>();
    CadPendente *cad = _dataCadastroPendente->buscaByChave(chaveCad);
    if (!cad)
    {
      std::cout << "Cadastro não encontrado!" << std::endl;
      return RetornoController::Completo;
    }
    // Completa dados caso seja cadastro interno
    if (cad->getTipoCadastro() == TipoCadastro::Interno)
    {
      Usuario *usuario = _dataUsuario->buscaUsuarioByChave(cad->getChaveUsu());
      cad->setFromUsuario(usuario);
      delete usuario;
    }
    // Recupera a lista de modalidades (pra mostrar o nome) se for cliente
    std::vector<Modalidade> listaModalidade;
    if (cad->getTipo() == 'C')
    {
      listaModalidade = _dataModalidade->buscaListaModalidade();
    }
    finalizarTela();
    std::cout << "DETALHES DO CADASTRO" << std::endl;
    std::cout << "CHAVE: " << cad->getChaveCad() << std::endl;
    std::cout << "NOME: " << cad->getNome() << std::endl;
    std::cout << "TIPO DE CADASTRO: ";
    if (cad->getTipoCadastro() == TipoCadastro::Externo)
      std::cout << "Externo (Novo Usuário)" << std::endl;
    else
      std::cout << "Interno (Usuário Existente)" << std::endl;
    std::cout << "TIPO DE PERFIL: ";
    switch (cad->getTipo())
    {
    case 'C':
      std::cout << "Cliente" << std::endl;
      break;
    case 'P':
      std::cout << "Professor" << std::endl;
      break;
    default:
      std::cout << "Administrador" << std::endl;
    }
    // Procura a modalidade para printar o nome, caso seja cliente
    if (cad->getTipo() == 'C')
    {
      for (auto modalidade : listaModalidade)
        if (modalidade.getChaveMod() == cad->getChaveMod())
          std::cout << "MODALIDADE: " << modalidade.getNome() << std::endl;
    }
    std::cout << "APELIDO: " << cad->getApelido() << std::endl;
    std::cout << "DATA DE NASC.: " << cad->getDtNascimento() << std::endl;
    std::cout << "CPF: " << cad->getCpf() << std::endl;
    std::cout << "RG: " << cad->getRg() << std::endl;
    std::cout << "SEXO: " << (cad->getSexo() == 'M' ? "Masculino" : "Feminino") << std::endl;
    std::cout << "LOGIN: " << cad->getLogin() << std::endl;
    hold();
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

  return RetornoController::Completo;
}