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
        std::string nome;
        std::cout << "Digite o novo nome: ";
        nome = readLine();
        _dataUsuario->editaNome(_session->getSelectedUsuario()->getChaveUsu(), nome);
        _session->getSelectedUsuario()->setNome(nome);
        std::cout << "Valor editado com sucesso!" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarApelido()
{
  return handleExecution(
      [&]
      {
        std::string apelido;
        std::cout << "Digite o novo apelido: ";
        apelido = readLine();
        _dataUsuario->editaApelido(_session->getSelectedUsuario()->getChaveUsu(), apelido);
        _session->getSelectedUsuario()->setApelido(apelido);
        std::cout << "Valor editado com sucesso!" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarDtNascimento()
{
  return handleExecution(
      [&]
      {
        std::string dtNascimento;
        std::cout << "Digite a nova data de nascimento: ";
        dtNascimento = readLine();
        _dataUsuario->editaDtNascimento(_session->getSelectedUsuario()->getChaveUsu(), dtNascimento);
        _session->getSelectedUsuario()->setDtNascimento(dtNascimento);
        std::cout << "Valor editado com sucesso!" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarCpf()
{
  return handleExecution(
      [&]
      {
        std::string cpf;
        std::cout << "Digite o novo CPF: ";
        cpf = readLine();
        _dataUsuario->editaCpf(_session->getSelectedUsuario()->getChaveUsu(), cpf);
        _session->getSelectedUsuario()->setCpf(cpf);
        std::cout << "Valor editado com sucesso!" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarSexo()
{
  return handleExecution(
      [&]
      {
        char sexo;
        std::cout << "Digite o novo sexo (M/F): ";
        sexo = std::toupper(readVal<char>(
            [&](char sexo)
            {
              if (std::tolower(sexo) != 'm' && std::tolower(sexo) != 'f')
              {
                std::cout << "Opção inválida!" << std::endl;
                return false;
              }
              return true;
            }));
        _dataUsuario->editaSexo(_session->getSelectedUsuario()->getChaveUsu(), sexo);
        _session->getSelectedUsuario()->setSexo(sexo);
        std::cout << "Valor editado com sucesso!" << std::endl;
      });
}

RetornoController ControllerEditarUsuario::editarLogin()
{
  return handleExecution(
      [&]
      {
        std::string login;
        std::cout << "Digite o novo login: ";
        login = readLine();
        _dataUsuario->editaLogin(_session->getSelectedUsuario()->getChaveUsu(), login);
        _session->getSelectedUsuario()->setLogin(login);
        std::cout << "Valor editado com sucesso!" << std::endl;
      });
}