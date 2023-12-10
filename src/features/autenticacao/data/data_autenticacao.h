#ifndef INF112_DATA_AUTENTICACAO_H
#define INF112_DATA_AUTENTICACAO_H
#include <vector>
#include <string>
#include "cad_pendente.h"
#include "usuario.h"
#include "database.h"
#include "enums.h"

class DataAutenticacao
{
private:
  Database *_database;

public:
  DataAutenticacao(Database *database);
  void inscreveCadastroPendente(CadPendente *cad);
  Usuario *buscaUsuario(std::string login);
  bool existeLogin(std::string login);
};

#endif