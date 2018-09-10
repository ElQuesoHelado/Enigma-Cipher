#include "enigma.h"
#include <iostream>

Enigma::Enigma()
{
}

int Modulo(int a, int b)
{
    int r = a - b * (a / b);
    return (r < 0) ? r += b : r;
}

void Enigma::getPosi(std::string x, std::string y, std::string z)
{
    posrizq = int(alfabeto.find(x));
    posrmed = int(alfabeto.find(y));
    posrder = int(alfabeto.find(z));
}

void Enigma::getLim(std::string x, std::string y, std::string z)
{
    limizq = alfabeto.find(x);
    limmed = alfabeto.find(y);
    limder = alfabeto.find(z);
}

void Enigma::getMensaje(std::string x)
{
    input = x;
}

void Enigma::getRot(int x, int y, int z)
{
    abcrotder = abecerotores[z - 1];
    abcrotmed = abecerotores[y - 1];
    abcrotizq = abecerotores[x - 1];

    //Limites por default
    limder = alfabeto.find(limites[z - 1]);
    limmed = alfabeto.find(limites[y - 1]);
    limizq = alfabeto.find(limites[x - 1]);
}

void Enigma::operar(std::string& x, const std::string& buscar, const std::string& reemplazar, int giros)
{
    int base = int(buscar.length());

    //abecedario es estatico
    //Suma de giro en el abecedario
    int columna = int(alfabeto.find(x)) + giros;
    columna = Modulo(columna, base);
    x = alfabeto[static_cast<unsigned long>(columna)];

    //busqueda y reemplazo con los abecedarios
    columna = int(buscar.find(x));
    x = reemplazar[static_cast<unsigned long>(columna)];

    //Abecedario estatico
    //Se reduce giros
    columna = int(alfabeto.find(x)) - giros;
    columna = Modulo(columna, base);
    x = alfabeto[static_cast<unsigned long>(columna)];
}

std::string Enigma::execute()
{
    std::string agregar;
    std::string result;
    int tamanio = int(input.length());
    int base = int(alfabeto.length());
    int limmedanterior = Modulo(limmed - 1, base);

    for (int i = 0; i < tamanio; i++) {
        agregar = input[static_cast<unsigned long>(i)];

        //step derecha
        posrder = Modulo(++posrder, base);
        if (posrder == limder) {
            posrmed = Modulo(++posrmed, base);

            //check medio double step
            if (posrmed == limmedanterior) {
                posrmed = Modulo(++posrmed, base);
            }

            //step normal medio
            if (posrmed == limmed) {
                posrizq = Modulo(++posrizq, base);
            }
        }

        //Rotor derecha
        operar(agregar, alfabeto, abcrotder, posrder);

        //Rotor medio
        operar(agregar, alfabeto, abcrotmed, posrmed);

        //Rotor izquierda
        operar(agregar, alfabeto, abcrotizq, posrizq);

        //Reflector
        operar(agregar, alfabeto, abecereflect, 0);

        //Rotor izquierda inversa
        operar(agregar, abcrotizq, alfabeto, posrizq);

        //Rotor medio inversa
        operar(agregar, abcrotmed, alfabeto, posrmed);

        //Rotor derecha inversa
        operar(agregar, abcrotder, alfabeto, posrder);

        //append a result
        result += agregar;
    }
    return result;
}
