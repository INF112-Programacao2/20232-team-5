#include "menu_cadastro_pendente.h"

MenuCadastroPendente::MenuCadastroPendente(std::string title, ControllerCadastroPendente *controllerCadastroPendente) : Menu(title), _controllerCadastroPendente(controllerCadastroPendente)
{
  inicializarOpcoes();
}

void MenuCadastroPendente::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Listar Todos", std::bind(&ControllerCadastroPendente::listaTodos, _controllerCadastroPendente)));
  _opcaoList.push_back(OpcaoMenu("Ver Detalhes", std::bind(&ControllerCadastroPendente::verDetalhes, _controllerCadastroPendente)));
  _opcaoList.push_back(OpcaoMenu("Rejeitar", std::bind(&ControllerCadastroPendente::rejeitaCadastro, _controllerCadastroPendente)));
  _opcaoList.push_back(OpcaoMenu("Aprovar", std::bind(&ControllerCadastroPendente::aprovaCadastro, _controllerCadastroPendente)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}