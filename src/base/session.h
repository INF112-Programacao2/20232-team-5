#ifndef INF112_SESSION_H
#define INF112_SESSION_H
#include "usuario.h"
#include "modalidade.h"

class Session
{
private:
  Usuario *_usuario;
  int _currentPerfil;
  Usuario *_selectedUsuario;
  Modalidade _selectedModalidade;

public:
  Session();
  ~Session();

  // Getters
  Usuario *getUsuario();
  int getCurrentPerfil();
  Usuario *getSelectedUsuario();
  Modalidade getSelectedModalidade();

  // Setters
  void setUsuario(Usuario *usuario);
  void setCurrentPerfil(int currentPerfil);
  void setSelectedUsuario(Usuario *usuario);
  void setSelectedModalidade(Modalidade modalidade);
};

#endif