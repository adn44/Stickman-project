#include <memory>
#include "../include/Singleton/Menu.h"

int main(void)
{
   Menu& menu(Menu::getInstance());
   menu.action();

    return EXIT_SUCCESS;
}
