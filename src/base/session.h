#ifndef INF112_SESSION_H
#define INF112_SESSION_H
#include "usuario.h"

class Session
{
private:
  Usuario *_usuario;
  int _currentPerfil;

public:
  Session();
  ~Session();

  // Getters
  Usuario *getUsuario();
  int getCurrentPerfil();

  // Setters
  void setUsuario(Usuario *usuario);
  void setCurrentPerfil(int currentPerfil);
};

#endif