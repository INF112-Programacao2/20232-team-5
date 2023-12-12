#include "session.h"

Session::Session()
{
  _usuario = nullptr;
  _selectedUsuario = nullptr;
  _selectedAluno = nullptr;
  _currentPerfil = 0;
}

Session::~Session()
{
  if (_usuario != nullptr)
    delete _usuario;
}

Usuario *Session::getUsuario()
{
  return _usuario;
}

int Session::getCurrentPerfil()
{
  return _currentPerfil;
}

Usuario *Session::getSelectedUsuario()
{
  return _selectedUsuario;
}

Modalidade Session::getSelectedModalidade()
{
  return _selectedModalidade;
}

Aluno *Session::getSelectedAluno()
{
  return _selectedAluno;
}

void Session::setUsuario(Usuario *usuario)
{
  _usuario = usuario;
}

void Session::setCurrentPerfil(int currentPerfil)
{
  _currentPerfil = currentPerfil;
}

void Session::setSelectedUsuario(Usuario *selectedUsuario)
{
  _selectedUsuario = selectedUsuario;
}

void Session::setSelectedModalidade(Modalidade modalidade)
{
  _selectedModalidade = modalidade;
}

void Session::setSelectedAluno(Aluno *aluno)
{
  _selectedAluno = aluno;
}