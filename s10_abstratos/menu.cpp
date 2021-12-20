#include <iostream>
#include <sstream>

class Carro {
    int numPessoas {0};
public:
    void entrar(){
        if (numPessoas < 5) {
            numPessoas++;
        } else {
            throw std::runtime_error("Carro lotado");
        }
    }
    void sair() {
        if (numPessoas > 0) {
            numPessoas--;
        } else {
            throw std::runtime_error("Carro vazio");
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Carro& c);
};
std::ostream& operator<<(std::ostream& os, const Carro& c) {
    os << "Carro com " << c.numPessoas << " pessoas";
    return os;
}



int main(){
    Carro carro;
    while(true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << '\n';
        try {
            if (cmd == "end") {
                break;
            } else if (cmd == "in") {
                carro.entrar();
            } else if (cmd == "out") {
                carro.sair();
            } else if (cmd == "show") {
                std::cout << carro << std::endl;
            } else {
                std::cout << "fail: comando invalido" << '\n';
            }
        } catch (std::runtime_error& e) {
            std::cout << e.what() << '\n';
        }
    }
    return 0;
}