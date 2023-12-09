#include "menu_opcoes_usuario.h"
#include "opcao_menu.h"
#include "global.h"
#include "controller_autenticacao.h"

MenuOpcoesUsuario::MenuOpcoesUsuario(std::string title, Session *session, ControllerOpcoesUsuario *controllerOpcoesUsuario, MenuEditarUsuario *menuEditarUsuario) : Menu(title), _session(session), _controllerOpcoesUsuario(controllerOpcoesUsuario), _menuEditarUsuario(menuEditarUsuario)
{
  inicializarOpcoes();
}

void MenuOpcoesUsuario::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Alternar perfil", std::bind(&ControllerOpcoesUsuario::alternaPerfil, _controllerOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Trocar senha", std::bind(&ControllerOpcoesUsuario::trocaSenha, _controllerOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Ver dados", std::bind(&ControllerOpcoesUsuario::verDados, _controllerOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Editar dados", std::bind(&MenuEditarUsuario::executar, _menuEditarUsuario)));
  //_opcaoList.push_back(OpcaoMenu("Perfis", std::bind(&ControllerOpcoesUsuario::trocaSenha, _ControllerOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Solicitar novo cadastro", std::bind(&ControllerOpcoesUsuario::novoCadastro, _controllerOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}

RetornoController MenuOpcoesUsuario::executar()
{
  _session->setSelectedUsuario(_session->getUsuario());
  RetornoController retorno = Menu::executar();
  return retorno;
}