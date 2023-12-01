#include "data_autenticacao.h"

DataAutenticacao::DataAutenticacao(PGconn *conn)
{
  _conn = conn;
}

void DataAutenticacao::inscreveCadastroPendente(CadPendente *cad)
{
  // Mock
}

Usuario *DataAutenticacao::buscaUsuario(std::string login)
{
  // Mock
  // return nullptr;
  Usuario *u = new Usuario(1, "João", "Joaozin", "17/04/2003", "10164444602", "20834320", 'M', "joaovitor", "senha123");
  return u;
}

std::vector<Perfil> DataAutenticacao::buscaPerfis(int chaveUsu)
{
  // Mock
  return {
      Perfil(1, 'A'),
      // Perfil(2, 'C'),
  };
}

bool DataAutenticacao::existeLogin(std::string login)
{
  // Mock
  return false;
  // return true;
}