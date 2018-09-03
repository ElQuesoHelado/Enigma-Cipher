#include "enigma.h"
#include <iostream>

int main()
{
    Enigma emisor;
    emisor.getPosi('H', 'D', 'X');
    emisor.getClave(1, 2, 3);
    emisor.getLim('R', 'F', 'W');
    //    emisor.getMensaje("CASA");
    //    emisor.getMensaje("CAZA");
    //    emisor.getMensaje("YAPA");
    //    emisor.getMensaje("MURCIELAGO");
    //    emisor.getMensaje("ABCDEFGHIJKLMZZQTXYQZSPPLMNXCVQ");
    emisor.getMensaje("ABCDEFGHIJKLMZZQTXYQZSPPLMZZXXYY");
    emisor.execute();
}
