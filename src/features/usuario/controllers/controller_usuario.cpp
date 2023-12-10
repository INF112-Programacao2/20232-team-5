#include "controller_usuario.h"
#include <vector>
#include "usuario.h"

ControllerUsuario::ControllerUsuario(Session *session, DataUsuario *dataUsuario, ControllerOpcoesUsuario *controllerOpcoesUsuario, MenuEditarUsuario *menuEditarUsuario) : _session(session), _dataUsuario(dataUsuario), _controllerOpcoesUsuario(controllerOpcoesUsuario), _menuEditarUsuario(menuEditarUsuario) {}

RetornoController ControllerUsuario::listaTodos()
{
  return handleExecution(
      [&]
      {
        std::cout << "LISTA DE USUÁRIOS" << std::endl;
        std::vector<Usuario> listaUsuario = _dataUsuario->buscaListaUsuario();
        if (!listaUsuario.size())
        {
          std::cout << "Lista vazia!" << std::endl;
          return;
        }
        for (auto usuario : listaUsuario)
        {
          std::cout << "CHAVE: " << usuario.getChaveUsu() << " | NOME: " << usuario.getNome() << std::endl;
        }
        hold();
      });
}

RetornoController ControllerUsuario::verDados()
{
  int chaveUsu;
  Usuario *usu;
  handleExecution(
      [&]
      {
        std::cout << "Informe a chave do usuário: ";
        chaveUsu = readVal<int>();
        usu = _dataUsuario->buscaUsuarioByChave(chaveUsu);
        if (!usu)
        {
          std::cout << "Usuário não encontrado!" << std::endl;
          return;
        }
        _session->setSelectedUsuario(usu);
        _controllerOpcoesUsuario->verDados();
      });
  if (usu)
    delete usu;
  return RetornoController::Completo;
}

RetornoController ControllerUsuario::editarDados()
{
  int chaveUsu;
  Usuario *usu;
  handleExecution(
      [&]
      {
        std::cout << "Informe a chave do usuário: ";
        chaveUsu = readVal<int>();
        usu = _dataUsuario->buscaUsuarioByChave(chaveUsu);
        if (!usu)
        {
          std::cout << "Usuário não encontrado!" << std::endl;
          return;
        }
        _session->setSelectedUsuario(usu);
        _menuEditarUsuario->executar();
      });
  if (usu)
    delete usu;
  return RetornoController::Completo;
}