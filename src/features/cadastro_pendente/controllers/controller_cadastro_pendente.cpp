#include "controller_cadastro_pendente.h"
#include "cad_pendente.h"
#include "database_error.h"
#include "enums.h"
#include "graduacao.h"
#include "aluno.h"

ControllerCadastroPendente::ControllerCadastroPendente(Session *session, DataCadastroPendente *dataCadastroPendente, DataUsuario *dataUsuario, DataModalidade *dataModalidade, DataAutenticacao *dataAutenticacao, DataGraduacao *dataGraduacao, DataAluno *dataAluno, DataPerfil *dataPerfil) : _session(session), _dataCadastroPendente(dataCadastroPendente), _dataUsuario(dataUsuario), _dataModalidade(dataModalidade), _dataAutenticacao(dataAutenticacao), _dataGraduacao(dataGraduacao), _dataAluno(dataAluno), _dataPerfil(dataPerfil) {}

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
  return handleExecution(
      [&]
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
        hold();
      });
}

RetornoController ControllerCadastroPendente::verDetalhes()
{
  CadPendente *cad;
  handleExecution(
      [&]
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
          std::cout << "MODALIDADE: " << getNomeCategoria(cad, listaModalidade) << std::endl;
        std::cout << "APELIDO: " << cad->getApelido() << std::endl;
        std::cout << "DATA DE NASC.: " << cad->getDtNascimento() << std::endl;
        std::cout << "CPF: " << cad->getCpf() << std::endl;
        std::cout << "RG: " << cad->getRg() << std::endl;
        std::cout << "SEXO: " << (cad->getSexo() == 'M' ? "Masculino" : "Feminino") << std::endl;
        std::cout << "LOGIN: " << cad->getLogin() << std::endl;
        hold();
      });
  if (cad)
    delete cad;

  return RetornoController::Completo;
}

RetornoController ControllerCadastroPendente::rejeitaCadastro()
{
  int chaveCad;
  CadPendente *cad;
  handleExecution(
      [&]
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
      });
  if (cad)
    delete cad;
  return RetornoController::Completo;
}

RetornoController ControllerCadastroPendente::aprovaCadastro()
{
  int chaveCad;
  CadPendente *cad = nullptr;
  Usuario *usu = nullptr;
  Aluno *aluno = nullptr;
  Graduacao *grad = nullptr;
  handleExecution(
      [&]
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
        std::cout << "Confirmar a aprovação (S/N)?" << std::endl;
        std::cout << "Sua resposta: ";
        char resp = readVal<char>(
            [&](char val)
            {
              if (std::tolower(val) != 's' && std::tolower(val) != 'n')
                return false;
              return true;
            });

        if (std::tolower(resp) == 's')
        {

          // Instancia usuário
          usu = Usuario::fromCadPendente(cad);
          bool existePerfil = false;
          // Se for novo usuário, cria nova instância no banco
          if (cad->getTipoCadastro() == TipoCadastro::Externo)
            usu->setChaveUsu(_dataUsuario->criaUsuario(usu));
          else
          {
            // Se não for usuário existente, vê se já possui o tipo de perfil que se quer cadastrar
            std::vector<TipoPerfil> listaPerfil = _dataPerfil->buscaPerfis(usu->getChaveUsu());
            for (auto perfil : listaPerfil)
              if (perfil == cad->getTipo())
              {
                existePerfil = true;
                break;
              }
          }
          // Cria perfil se não existe
          if (!existePerfil)
            _dataCadastroPendente->criaPerfil(usu->getChaveUsu(), cad->getTipo());
          // Se for cliente, cria o aluno
          if (cad->getTipo() == TipoPerfil::Cliente)
          {
            // Primeiro busca a graduação inicial da modalidade em questão
            grad = _dataGraduacao->buscaGraduacaoInicial(cad->getChaveMod());
            if (!grad)
            {
              std::cout << "Modalidade não possui graduação inicial! Não há como inscrever o aluno na modalidade!" << std::endl;
            }
            else
            {
              aluno = Aluno::fromUsuario(usu);
              aluno->setChaveGrd(grad->getChaveGrd());
              _dataAluno->criaAluno(aluno);
            }
          }
          _dataCadastroPendente->deletaCadastro(cad->getChaveCad());
          std::cout << "Cadastros realizados!" << std::endl;
        }
      });
  if (cad)
    delete cad;
  if (usu)
    delete usu;
  if (aluno)
    delete aluno;
  if (grad)
    delete grad;
  return RetornoController::Completo;
}