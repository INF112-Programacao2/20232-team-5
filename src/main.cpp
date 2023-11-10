#include <iostream>
#include "menu_inicial.h"

int main()
{
    MenuInicial menu("Menu Inicial");
    menu.executar();
    std::cout << "Volte sempre!\n";
    return 0;
}
