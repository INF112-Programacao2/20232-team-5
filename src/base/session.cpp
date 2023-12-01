#include "session.h"

Session::Session()
{
  _usuario = nullptr;
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

void Session::setUsuario(Usuario *usuario)
{
  _usuario = usuario;
}

void Session::setCurrentPerfil(int currentPerfil)
{
  _currentPerfil = currentPerfil;
}