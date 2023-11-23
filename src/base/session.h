#ifndef INF112_SESSION_H
#define INF112_SESSION_H
#include "usuario.h"

class Session
{
private:
  Usuario *_usuario;

public:
  Session();
  Usuario *getUsuario();
  void setUsuario(Usuario *usuario);
};

#endif