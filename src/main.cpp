#include <iostream>
#include "main_initializer.h"

int main()
{
    MainInitializer *initializer = new MainInitializer();
    if (!initializer->initialize())
        exit(1);
    initializer->executar();
    delete initializer;
    std::cout << "Volte sempre!\n";
    return 0;
}
