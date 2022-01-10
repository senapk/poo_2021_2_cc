#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map> 
#include <memory>
using namespace std;

class Fone {
    string label {""};
    string numero {""};
public:
    Fone(string label, string numero) : label(label), numero(numero) {}
    string getLabel() { return label; }
    string getNumero() { return numero; }
    friend ostream& operator<<(ostream& os, const Fone& fone);
};
ostream& operator<<(ostream& os, const Fone& fone) {
    os << fone.label << ":" << fone.numero;
    return os;
}