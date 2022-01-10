#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map> 
#include <memory>
#include "fone.hpp"

using namespace std;

class Contato {
    string nome;
    vector<Fone> fones;
    bool favorito {false};
public:
    Contato(string nome) {
        this->nome = nome;
    }
    string getNome() {
        return nome;
    }
    void addFone(Fone fone) {
        fones.push_back(fone);
    }
    void setFavorito(bool favorito) {
        this->favorito = favorito;
    }
    bool getFavorito() {
        return favorito;
    }
    friend ostream& operator<<(ostream& os, Contato& c);
};
ostream& operator<<(ostream& os, Contato& c) {
    os << (c.favorito ? "* ":"- ") << c.nome;
    for (auto fone : c.fones)
        os << " " << fone;
    return os;
}
