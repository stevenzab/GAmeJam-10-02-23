#include "include/Core.hpp"

int main(int ac, char **av)
{
    Core c;
    try {
        c.loop();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}