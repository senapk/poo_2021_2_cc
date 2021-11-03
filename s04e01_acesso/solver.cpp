#include <iostream>

class Carro {
private:
    int idade;
public:
    std::string nome;

    Carro(std::string nome, int idade) {
        this->nome = nome;
        this->idade = idade;
    }

    int getIdade() {
        return this->idade;
    }

    void setIdade(int idade) {
        if (idade > this->idade) {
            this->idade = idade;
        } else {
            std::cout << "Idade não pode ser menor que a atual" << std::endl;
        }
    }

    void envelhecer() {
        this->idade++;
    }
};

int main() {
    Carro pessoa("Joao", 20);
    pessoa.envelhecer();
    pessoa.envelhecer();
    std::cout << pessoa.getIdade() << std::endl;
    pessoa.setIdade(0);
    pessoa.setIdade(24);
    return 0;
}
