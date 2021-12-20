#include <iostream>
#include <vector>

//interface: não tem atributos, nem implementações
//classe abstrata: posso ter atributos, posso ter algumas implementações concretas
class Forma {
private:
    std::string nome;
public:
    Forma(std::string nome) : nome(nome) {}
    virtual std::string getNome(){
        return nome;
    }; 
    virtual void setNome(std::string nome){
        this->nome = nome;
    };
    virtual double getArea() = 0; //virtual puro

    virtual ~Forma() {};
};

class Circulo : public Forma {
    double raio;
public:
    Circulo(double r) : Forma("Circulo"), raio(r) {}

    double getArea() override {
        return 3.14 * raio * raio; 
    }
};

class Retangulo : public Forma {
    double base, altura;
public:
    Retangulo(double b, double a) : Forma("Retangulo"), base(b), altura(a) {}
    double getArea() override {
        return base * altura; 
    }
};

class Quadrado : public Retangulo {
public:
    Quadrado(double lado): Retangulo(lado, lado) {
        this->setNome("Quadrado");
    }
};

#include <memory>
int main() {
    std::vector<std::shared_ptr<Forma>> formas;

    formas.push_back(std::make_shared<Circulo>(2));
    formas.push_back(std::make_shared<Retangulo>(2, 3));
    formas.push_back(std::make_shared<Quadrado>(2));

    for (auto f : formas) {
        std::cout << f->getNome() << ":" << f->getArea() << std::endl;
    }
    return 0;
}
