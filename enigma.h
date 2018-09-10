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
const std::string limites[5]={"R","F","W","K","A"};

class Enigma {
private:
    std::string input, abcrotizq, abcrotmed, abcrotder;
    int limizq, limmed, limder, posrizq, posrmed, posrder;

public:
    void getRot(int, int, int);
    void getPosi(std::string, std::string, std::string);
    void getLim(std::string, std::string, std::string);
    void getMensaje(std::string);
    void operar(std::string&, const std::string&, const std::string&, int);
    std::string execute();
    Enigma();
};

#endif // ENIGMA_H
