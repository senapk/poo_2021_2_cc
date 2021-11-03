#include <iostream>

class Carro {
private:
    int gas;
    int maxGas;
public:
    Carro(std::string nome, int maxGas) {
        this->maxGas = maxGas;
        this->gas = maxGas;
    }
    int getMaxGas() {
        return this->maxGas;
    }
    int getGas() {
        return this->gas;
    }
    void setGas(int gas) {
        if (gas < 0) {
            this->gas = 0;
        } else if (gas > this->maxGas) {
            this->gas = this->maxGas;
        } else {
            this->gas = gas;
        }
    }
};

int main() {

}
