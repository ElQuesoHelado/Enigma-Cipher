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

void Enigma::getPosi(char x, char y, char z)
{
    posrizq = int(alfabeto.find(x));
    posrmed = int(alfabeto.find(y));
    posrder = int(alfabeto.find(z));
}

void Enigma::getLim(char x, char y, char z)
{
    limizq = alfabeto.find(x);
    limmed = alfabeto.find(y);
    limder = alfabeto.find(z);
}

void Enigma::getMensaje(std::string x)
{
    input = x;
}

void Enigma::getClave(int x, int y, int z)
{
    abcrotder = abecerotores[z - 1];
    abcrotmed = abecerotores[y - 1];
    abcrotizq = abecerotores[x - 1];
}

void Enigma::operar(char& x, const std::string& buscar, const std::string& reemplazar, int giros)
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
    char agregar;
    std::string result;
    int tamanio = int(input.length());
    int base = int(alfabeto.length());
    bool stepdoble = false,
         steprt2 = false,
         steprt1 = false;

    for (int i = 0; i < tamanio; i++) {
        agregar = input[static_cast<unsigned long>(i)];

        //        posrder=Modulo(++posrder, base);
        posrder++;
        posrder = posrder % 26;
        //        check limites
        if (posrder == limder || stepdoble) {
            //            posrmed = Modulo(++posrmed, base);
            posrmed++;
            posrmed = posrmed % 26;
            stepdoble = false;
            if (posrmed == limmed - 1)
                stepdoble = true;
        }
        if (posrmed == limmed) {
            //            posrizq = Modulo(++posrizq, base);
            posrizq++;
            posrizq = posrizq % 26;
        }

        if (i == tamanio - 1 || i == 0) {
            std::cout << "posicion rt derecha: " << posrder << std::endl;
            std::cout << "posicion rt medio: " << posrmed << std::endl;
            std::cout << "posicion rt izquerda: " << posrizq << "\n\n"
                      << std::endl;
        }

        //Rotor derecha
        operar(agregar, alfabeto, abcrotder, posrder);
        //        std::cout << "RT derecha: " << agregar << std::endl;

        //Rotor medio
        operar(agregar, alfabeto, abcrotmed, posrmed);
        //        std::cout << "RT Medio: " << agregar << std::endl;

        //Rotor izquierda
        operar(agregar, alfabeto, abcrotizq, posrizq);
        //        std::cout << "RT izquierda: " << agregar << std::endl;

        //Reflector
        operar(agregar, alfabeto, abecereflect, 0);
        //        std::cout << "Reflector: " << agregar << std::endl;

        //Rotor izquierda inversa
        operar(agregar, abcrotizq, alfabeto, posrizq);
        //        std::cout << "RT izquierda inversa: " << agregar << std::endl;

        //Rotor medio inversa
        operar(agregar, abcrotmed, alfabeto, posrmed);
        //        std::cout << "RT medio inversa: " << agregar << std::endl;

        //Rotor derecha inversa
        operar(agregar, abcrotder, alfabeto, posrder);
        //        std::cout << "RT derecha inversa: " << agregar << std::endl;

        //append a result
        result += agregar;
    }
    std::cout << "Valor permutado: " << result << std::endl;
    return result;
}
