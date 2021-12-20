#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <vector>

class Corredor {
protected:
    float x {0};
    std::string nome;
public:
    Corredor(std::string nome) : nome(nome) {}
    float getX() {
        return x;
    }
    virtual void correr() = 0;
    friend std::ostream& operator<<(std::ostream& os, Corredor& corredor);
};
std::ostream& operator<<(std::ostream& os, Corredor& corredor) {
    os << corredor.nome << ":" << corredor.x;
    return os;
}

class Penelope : public Corredor {
public:
    Penelope() : Corredor("Penelope") {}
    void correr() override {
        x += 1;
    }
};

class Mutley : public Corredor {
    int probAndar;
public:
    Mutley(int probAndar = 50) : Corredor("Mutley"), probAndar{probAndar} {}
    void correr() override {
        if((rand() % 100) < probAndar) {
            x += 2;
        }
    }
};

class Xerife : public Corredor {
    float vel = 0.5;
    float inc = 0.1;
public:
    Xerife(float velInicial, float inc) : Corredor("Xerife"), vel{velInicial}, inc{inc} {}
    void correr() override {
        x += vel;
        vel += inc;
    }
};

class Corrida {
    std::vector<std::shared_ptr<Corredor>> corredores;
    float distancia;
public:
    Corrida(float distancia) : distancia(distancia) {}
    void adicionaCorredor(std::shared_ptr<Corredor> corredor) {
        corredores.push_back(corredor);
    }
    void darLargada() {
        while (!temGanhador()) {
            for (auto corredor : corredores) {
                corredor->correr();
            }
            this->mostrarStatus();
            getchar();
        }
    }
    bool temGanhador() {
        for(auto corredor : corredores) {
            if(corredor->getX() >= distancia) {        
                Xerife* xerife = dynamic_cast<Xerife*>(corredor.get());
                if(xerife != nullptr) {
                    return true;
                }
                distancia = corredor->getX() + 1;
            }
        }
        return false;
    }
    void mostrarStatus() {
        for(auto corredor : corredores) {
            std::cout << *corredor << " ";
        }
        std::cout << std::endl;
    }
    void correr() {
        for(auto corredor : corredores) {
            corredor->correr();
        }
    }
};

int main() {
    srand(time(NULL));
    Corrida corrida(10);
    corrida.adicionaCorredor(std::make_shared<Penelope>());
    corrida.adicionaCorredor(std::make_shared<Mutley>(100));
    corrida.adicionaCorredor(std::make_shared<Xerife>(0.5, 0.15));
    corrida.darLargada();
    return 0;
}