#include "controller_perfil.h"
#include <vector>
#include "usuario.h"

// Classe responsável por controlar as operações de perfil
ControllerPerfil::ControllerPerfil(Session *session, DataPerfil *dataPerfil) : _session(session), _dataPerfil(dataPerfil) {}

std::string ControllerPerfil::getTipoStr(TipoPerfil tipo)
{
  switch (tipo)
  {
  case TipoPerfil::Cliente:
    return "Cliente";
  case TipoPerfil::Professor:
    return "Professor";
  default:
    return "Administrador";
  }
}

RetornoController ControllerPerfil::listaPerfilUsuario()
{
  return handleExecution(
      [&]
      {
        std::cout << "LISTA DE PERFIS" << std::endl;
        std::vector<TipoPerfil> listaPerfil = _dataPerfil->buscaPerfis(_session->getSelectedUsuario()->getChaveUsu());
        for (int i = 0; i < listaPerfil.size(); i++)
        {
          std::cout << "NUM: " << i + 1 << " | TIPO: " << getTipoStr(listaPerfil[i]) << std::endl;
        }
      });
}

RetornoController ControllerPerfil::adicionaPerfilUsuario()
{
  char tipo;
  Usuario *usuario = _session->getSelectedUsuario();
  return handleExecution(
      [&]
      {
        std::cout << "Informe o tipo de perfil que você deseja adicionar:" << std::endl;
        std::cout << "C - Cliente | P - Professor | A - Administrador" << std::endl;
        std::cout << "Sua escolha: ";
        tipo = readVal<char>(
            [&](char val)
            {
              val = std::toupper(val);
              if (val != 'C' && val != 'P' && val != 'A')
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            });
        tipo = std::toupper(tipo);
        if (_dataPerfil->checaTemPerfil(usuario->getChaveUsu(), static_cast<TipoPerfil>(tipo)))
        {
          std::cout << "Usuário já possui esse perfil!" << std::endl;
          return;
        }
        _dataPerfil->criaPerfil(usuario->getChaveUsu(), static_cast<TipoPerfil>(tipo));
        std::cout << "Perfil criado com sucesso!" << std::endl;
      });
}

RetornoController ControllerPerfil::deletaPerfilUsuario()
{
  int index;
  Usuario *usuario = _session->getSelectedUsuario();
  char opcao;
  return handleExecution(
      [&]
      {
        std::vector<TipoPerfil> listaPerfil = _dataPerfil->buscaPerfis(usuario->getChaveUsu());
        if (listaPerfil.size() == 1)
        {
          std::cout << "O usuário só possui 1 perfil! Não é possível deletar!" << std::endl;
          return;
        }
        std::cout << "Informe o número do perfil: ";
        index = readVal<int>();
        if (index < 1 || index > listaPerfil.size())
        {
          std::cout << "Perfil não encontrado!" << std::endl;
          return;
        }
        index--;
        if (usuario->getChaveUsu() == _session->getUsuario()->getChaveUsu() && _session->getCurrentPerfil() == index)
        {
          std::cout << "Você não pode excluir o perfil em que está navegando no momento!" << std::endl;
          return;
        }
        std::cout << "Deseja confirmar a remoção do perfil \"" << getTipoStr(listaPerfil[index]) << "\" (S/N)? ";
        opcao = readVal<char>(
            [&](char val)
            {
              val = std::tolower(val);
              if (val != 's' && val != 'n')
              {
                std::cout << "Escolha inválida!" << std::endl;
                return false;
              }
              return true;
            });
        opcao = std::tolower(opcao);
        if (opcao == 'n')
          return;
        _dataPerfil->removePerfil(usuario->getChaveUsu(), listaPerfil[index]);
        // Atualiza  perfis do usuário logado, caso ele tenha sido editado
        if (usuario->getChaveUsu() == _session->getUsuario()->getChaveUsu())
        {
          TipoPerfil tipoLogado = listaPerfil[_session->getCurrentPerfil()];
          std::vector<TipoPerfil> novaLista = _dataPerfil->buscaPerfis(usuario->getChaveUsu());
          _session->getUsuario()->setPerfilList(novaLista);
          for (int i = 0; i < novaLista.size(); i++)
            if (novaLista[i] == tipoLogado)
              _session->setCurrentPerfil(i);
        }
        std::cout << "Perfil removido com sucesso!" << std::endl;
      });
}