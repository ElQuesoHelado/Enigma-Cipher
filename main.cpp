#include "enigma.h"
#include <iostream>

int main()
{
    Enigma emisor;

    emisor.getPosi("A", "A", "A");

    emisor.getRot(1, 2, 3);

    emisor.getMensaje("VPKUW");

    std::string cifrado = emisor.execute();
    std::cout << "Cifrado: " << cifrado << std::endl;
}
