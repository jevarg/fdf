#include "Fdf.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Fdf fdf;

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " map.fdf" << std::endl;
        return 1;
    }

    fdf.start(argv[1]);
    fdf.stop();
    return 0;
}
