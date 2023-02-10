<<<<<<< Updated upstream
#include "include/Core.hpp"
=======
#include "include/Window.hpp"
>>>>>>> Stashed changes

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