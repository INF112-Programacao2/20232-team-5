#include "session.h"

Session::Session() {}

Usuario *Session::getUsuario()
{
  return _usuario;
}

void Session::setUsuario(Usuario *usuario)
{
  _usuario = usuario;
}