#include <iostream>
#include "fone.hpp"
//pessoa.hpp
class Pessoa {
public:
    std::string nome {"anonimo"};
    Fone fone;
    Pessoa(std::string nome, Fone fone);
};