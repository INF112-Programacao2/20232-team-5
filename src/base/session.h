#ifndef INF112_SESSION_H
#define INF112_SESSION_H
#include "usuario.h"

class Session
{
private:
  Usuario *_usuario;
  int _currentPerfil;
  Usuario *_selectedUsuario;

public:
  Session();
  ~Session();

  // Getters
  Usuario *getUsuario();
  int getCurrentPerfil();
  Usuario *getSelectedUsuario();

  // Setters
  void setUsuario(Usuario *usuario);
  void setCurrentPerfil(int currentPerfil);
  void setSelectedUsuario(Usuario *usuario);
};

#endif