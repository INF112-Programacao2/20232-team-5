#include "data_autenticacao.h"

void DataAutenticacao::inscreveCadastroPendente(CadPendente *cad)
{
  // Mock
}

Usuario *DataAutenticacao::buscaUsuario(std::string login)
{
  // Mock
  return new Usuario(1, "João", "Joaozin", "17/04/2003", "10164444602", "20834320", 'M', "joaovitor", "senha123");
}

std::vector<Perfil> DataAutenticacao::buscaPerfis(int chaveUsu)
{
  // Mock
  return {
      Perfil(1, 'C'),
      Perfil(2, 'P'),
  };
}