#include "menu_cliente.h"

MenuCliente::MenuCliente(std::string title, Session *session, MenuOpcoesUsuario *menuOpcoesUsuario, ControllerRegistrarPresenca *controllerRegistrarPresenca, ControllerDadosAluno *controllerDadosAluno) : Menu(title), _session(session), _menuOpcoesUsuario(menuOpcoesUsuario), _controllerRegistrarPresenca(controllerRegistrarPresenca), _controllerDadosAluno(controllerDadosAluno)
{
  inicializarOpcoes();
}

void MenuCliente::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Registrar Presença", std::bind(&ControllerRegistrarPresenca::registrarPresencaUsuarioLogado, _controllerRegistrarPresenca)));
  _opcaoList.push_back(OpcaoMenu("Ver Dados do Aluno", std::bind(&ControllerDadosAluno::mostraDados, _controllerDadosAluno)));
  _opcaoList.push_back(OpcaoMenu("Opções do Usuário", std::bind(&MenuOpcoesUsuario::executar, _menuOpcoesUsuario)));
  _opcaoList.push_back(OpcaoMenu("Logout", std::bind(logout)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}