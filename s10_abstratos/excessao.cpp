#include <iostream>
#include <stdexcept>

void funcao1() { //erro de logica
    //erro de logica
    //arquivo nao encontrado
    //problema de conexão
    std::cout << "funcao1() inicio" << std::endl;
    throw std::runtime_error("esqueceu um parametro");
    std::cout << "funcao1() fim" << std::endl;
}

void funcao2() {
    std::cout << "funcao2() inicio" << std::endl;
    try {
        funcao1();
    } catch (int e) {
        std::cout << "funcao2() capturou " << e << std::endl;
    }
    std::cout << "funcao2() fim" << std::endl;
}

void funcao3() {
    std::cout << "funcao3() inicio" << std::endl;
    try {
        funcao2();
    } catch (std::logic_error& e) {
        std::cout << "funcao3() catch logic " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "funcao3() catch exception " << e.what() << std::endl;
    }
    std::cout << "funcao3() fim" << std::endl;
}

int main() {
    funcao3();
}