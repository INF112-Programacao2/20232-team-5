#ifndef INF112_DATA_MODALIDADE_H
#define INF112_DATA_MODALIDADE_H
#include "database.h"
#include <vector>
#include "modalidade.h"

class DataModalidade
{
private:
  Database *_database;

public:
  DataModalidade(Database *database);
  // cadastrar modalidade
  void cadastraModalidade(Modalidade *modalidade);
  // Busca lista de modalidades do sistema
  std::vector<Modalidade> buscaListaModalidade();
  // Busca lista de modalidades disponíveis (não cadastradas) para um usuário
  std::vector<Modalidade> buscaListaModalidadesDisponiveis(int chaveUsu);
  // Busca lista de modalidades cadastradas para um usuário
  std::vector<Modalidade *> buscaListaModalidadesUsuario(int chaveUsu);

  // editar modalidade
  void editaModalidade(int chaveMod, std::string nome);
  // excluir modalidade
  void excluiModalidade(int chaveMod);
  // Busca modalidade pela chave
  Modalidade *buscaModalidade(int chaveMod);
};

#endif