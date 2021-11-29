#include <iostream>
#include "fone.hpp"
#include "pessoa.hpp"


//main.cpp
int main() {
    Pessoa pessoa("Joao", Fone("123456789"));
    std::cout << pessoa.fone.getNumber() << std::endl;
    return 0;
}


