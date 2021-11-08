#include <iostream>
#include <memory>
#include <vector>
#include <optional>

class Person {
public:
    std::string nome;
    int idade;

    Person(std::string nome = "", int idade = 0) : nome(nome), idade(idade) {}
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << p.nome << ":" << p.idade;
        return os;
    }
};

class Car {

    std::vector<std::shared_ptr<Person>> seats;
    bool validar_index(int index) {
        if (index < 0 || index >= (int) this->seats.size()) {
            std::cout << "Index invalido" << std::endl;
            return false;
        }
        return true;
    }

public:
    Car(int lugares): seats(lugares, nullptr) {
        // for (int i = 0; i < 5; i++) {
        //     seats.push_back(nullptr);
        // }
    }

    void inserir(std::shared_ptr<Person> person, int index) {
        if (!validar_index(index))
            return;
        
        if (seats[index] == nullptr) {
            seats[index] = person;
        } else {
            std::cout << "Posicao ocupada" << std::endl;
        }
    }
    std::shared_ptr<Person> remover(int index) {
        if (!validar_index(index))
            return nullptr;
        
        if (seats[index] != nullptr) {
            return std::exchange(seats[index], nullptr);
        }
        std::cout << "Não há ninguém no lugar " << index << std::endl;
        return nullptr;
    }

    void mover(int origem, int destino) {
        if(!validar_index(origem) || !validar_index(destino))
            return;
        if(this->seats[origem] == nullptr) {
            std::cout << "Não há ninguém no lugar " << origem << std::endl;
            return;
        }
        if(this->seats[destino] != nullptr) {
            std::cout << "Destino ocupado " << destino << std::endl;
            return;
        }
        this->seats[destino] = this->seats[origem];
        this->seats[origem] = nullptr;



    }

    friend std::ostream& operator<<(std::ostream& os, const Car& c) {
        os << "[ ";
        for (auto person : c.seats) {
            if (person != nullptr) {
                os << *person << " ";
            } else {
                os << "- ";
            }
        }
        os << "]";
        return os;
    }
};

int main() {
    Car car(5);
    std::cout << car << std::endl;
    car.inserir(std::make_shared<Person>("Joao", 20), 1);
    auto maria = std::make_shared<Person>("Maria", 90);
    car.inserir(maria, 1);
    car.inserir(maria, 0);
    std::cout << car << std::endl;
    auto pessoa = car.remover(0);

    std::cout << car << std::endl;
    std::cout << "Pessoa: " << *pessoa << std::endl;
}

struct Grafite{};

struct Lapiseira {
    std::shared_ptr<Grafite> bico;
    std::vector<std::shared_ptr<Grafite>> tambor;

    void puxar_grafite() {
        bico = tambor[0];
        tambor.erase(tambor.begin());
    }
};