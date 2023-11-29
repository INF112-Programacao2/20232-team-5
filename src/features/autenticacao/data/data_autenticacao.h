#ifndef INF112_DATA_AUTENTICACAO_H
#define INF112_DATA_AUTENTICACAO_H
#include <vector>
#include <string>
#include "cad_pendente.h"
#include "usuario.h"
#include "perfil.h"

class DataAutenticacao
{
public:
  void inscreveCadastroPendente(CadPendente *cad);
  Usuario *buscaUsuario(std::string login);
  std::vector<Perfil> buscaPerfis(int chaveUsu);
  bool existeLogin(std::string login);
};

#endif