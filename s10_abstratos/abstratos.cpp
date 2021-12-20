#include <iostream>

//classe concreta
class Pessoa {
    std::string nome;
    int idade;
};
//classe abstrata -> pode ter atributos, e pode ter métodos concretos ou abstratos


//interface -> não tem implementações nem atributos
class Imprimivel {
public:
    virtual void imprime() = 0;
};

