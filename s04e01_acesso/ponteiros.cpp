#include <iostream>

class Pessoa {
private:
    std::string nome;
    int idade;
public:
    Pessoa(std::string nome, int idade) : nome(nome), idade(idade) {
        std::cout << nome << " nascendo" << std::endl;
    }
    ~Pessoa() {
        std::cout << nome << " morrendo" << std::endl;
    }
    std::string getNome() { return nome; }
    int getIdade() { return idade; }
    friend std::ostream& operator<<(std::ostream& os, Pessoa& p){
        os << "Nome: " << p.getNome() << " Idade: " << p.getIdade();
        return os;
    }
};

class Moto {
private:
    Pessoa* pessoa;
public:
    Moto(Pessoa* pessoa) : pessoa(pessoa) {
        std::cout << pessoa->getNome() << " esta usando uma moto" << std::endl;
    }

    void setPessoa(Pessoa* pessoa) {
        this->pessoa = pessoa;
    }

    Pessoa* getPessoa() {
        return pessoa;
    }

    ~Moto() {
        if (this->pessoa != nullptr) {
            std::cout << pessoa->getNome() << " deixou de usar uma moto" << std::endl;
        }
    }
};


int main() {
    Moto *motoca = (Moto*) malloc(sizeof(Moto));
    Moto *motoca2 = new Moto(new Pessoa("Joao", 20));
    
    Moto motoca(nullptr);
    int x = 0;
    int *z;
    {
        int y;
        z = &y;
    }
    std::cout << z << *z;
    {
        Pessoa* pessoa = new Pessoa("Joao", 20);
        motoca.setPessoa(pessoa);
        std::cout << *pessoa << std::endl;
    }

}