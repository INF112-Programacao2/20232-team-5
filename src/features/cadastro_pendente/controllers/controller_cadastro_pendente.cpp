#include "controller_cadastro_pendente.h"
#include "cad_pendente.h"
#include "database_error.h"
#include "enums.h"

ControllerCadastroPendente::ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente, DataUsuario *dataUsuario, DataModalidade *dataModalidade) : _session(session), _dataCadastroPendente(dataCadastroPendente), _dataUsuario(dataUsuario), _dataModalidade(dataModalidade) {}

void ControllerCadastroPendente::completaDados(CadPendente *cad)
{
  Usuario *usuario = _dataUsuario->buscaUsuarioByChave(cad->getChaveUsu());
  cad->setFromUsuario(usuario);
  delete usuario;
}

std::string ControllerCadastroPendente::getTipoStr(CadPendente *cad)
{
  switch (cad->getTipo())
  {
  case TipoPerfil::Cliente:
    return "Cliente";
  case TipoPerfil::Professor:
    return "Professor";
  default:
    return "Administrador";
  }
}

std::string ControllerCadastroPendente::getNomeCategoria(CadPendente *cad, std::vector<Modalidade> listaModalidade)
{
  for (auto modalidade : listaModalidade)
    if (modalidade.getChaveMod() == cad->getChaveMod())
      return modalidade.getNome();
  return "Não encontrada";
}

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
        completaDados(&cadPendente);

      tipo = getTipoStr(&cadPendente);

      std::cout << "CHAVE: " << cadPendente.getChaveCad() << " | NOME: " << cadPendente.getNome() << " | TIPO: " << tipo;
      // Procura a modalidade para printar o nome, caso seja cliente
      if (cadPendente.getTipo() == TipoPerfil::Cliente)
        std::cout << " | MODALIDADE: " << getNomeCategoria(&cadPendente, listaModalidade);

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
  CadPendente *cad;
  try
  {
    int chaveCad;
    std::cout << "Informe a chave do cadastro: ";
    chaveCad = readVal<int>();
    cad = _dataCadastroPendente->buscaByChave(chaveCad);
    if (!cad)
    {
      std::cout << "Cadastro não encontrado!" << std::endl;
      return RetornoController::Completo;
    }
    // Completa dados caso seja cadastro interno
    if (cad->getTipoCadastro() == TipoCadastro::Interno)
      completaDados(cad);
    // Recupera a lista de modalidades (pra mostrar o nome) se for cliente
    std::vector<Modalidade> listaModalidade;
    if (cad->getTipo() == TipoPerfil::Cliente)
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
    std::cout << "TIPO DE PERFIL: " << getTipoStr(cad) << std::endl;
    // Procura a modalidade para printar o nome, caso seja cliente
    if (cad->getTipo() == TipoPerfil::Cliente)
      std::cout << " | MODALIDADE: " << getNomeCategoria(cad, listaModalidade);
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
  if (cad)
    delete cad;

  return RetornoController::Completo;
}

RetornoController ControllerCadastroPendente::rejeitaCadastro()
{
  int chaveCad;
  CadPendente *cad;
  try
  {
    // Solicita chave
    std::cout
        << "Informe a chave do cadastro: ";
    chaveCad = readVal<int>();
    cad = _dataCadastroPendente->buscaByChave(chaveCad);
    if (!cad)
    {
      std::cout << "Cadastro não encontrado!" << std::endl;
      return RetornoController::Completo;
    }
    // Completa dados caso seja cadastro interno
    if (cad->getTipoCadastro() == TipoCadastro::Interno)
      completaDados(cad);
    std::string tipo = getTipoStr(cad);
    // Confirma rejeição
    std::cout << "Cadastrado identificado: " << std::endl;
    std::cout << "CHAVE: " << cad->getChaveCad() << " | NOME: " << cad->getNome() << " | TIPO: " << tipo << std::endl;
    std::cout << "Confirmar a rejeição (S/N)?" << std::endl;
    std::cout << "Sua resposta: ";
    char resp = readVal<char>(
        [&](char val)
        {
          if (std::tolower(val) != 's' && std::tolower(val) != 'n')
            return false;
          return true;
        });
    // Rejeita
    if (std::tolower(resp) == 's')
    {
      _dataCadastroPendente->deletaCadastro(chaveCad);
      std::cout << "Cadastro rejeitado!" << std::endl;
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
  if (cad)
    delete cad;
  return RetornoController::Completo;
}

RetornoController ControllerCadastroPendente::aprovaCadastro()
{
  return RetornoController::Completo;
}