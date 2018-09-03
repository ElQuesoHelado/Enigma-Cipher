#ifndef ENIGMA_H
#define ENIGMA_H
#include <string>

const std::string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string abecereflect = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
const std::string abecerotores[5] = { "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
    "VZBRGITYUPSDNHLXAWMJQOFECK" };

class Enigma {
private:
    std::string input, abcrotizq, abcrotmed, abcrotder;
    int limizq, limmed, limder, posrizq, posrmed, posrder;

public:
    void getClave(int, int, int);
    void getPosi(char, char, char);
    void getLim(char, char, char);
    void getMensaje(std::string);
    void operar(char&, const std::string&, const std::string&, int);
    std::string execute();
    Enigma();
};

#endif // ENIGMA_H
