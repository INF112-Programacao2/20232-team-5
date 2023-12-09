#include "controller_editar_usuario.h"
#include "database_error.h"
#include <exception>

ControllerEditarUsuario::ControllerEditarUsuario(Session *session, DataUsuario *dataUsuario) : _session(session), _dataUsuario(dataUsuario)
{
}

RetornoController ControllerEditarUsuario::editarNome()
{
  return handleExecution(
      [&]
      {
        std::cout << "Edita nome" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarApelido()
{
  return handleExecution(
      [&]
      {
        std::cout << "Edita apelido" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarDtNascimento()
{
  return handleExecution(
      [&]
      {
        std::cout << "Edita data" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarCpf()
{
  return handleExecution(
      [&]
      {
        std::cout << "Edita cpf" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarSexo()
{
  return handleExecution(
      [&]
      {
        std::cout << "Edita sexo" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarLogin()
{
  return handleExecution(
      [&]
      {
        std::cout << "Edita login" << std::endl;
      });
}