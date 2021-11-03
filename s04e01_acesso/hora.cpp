#include <iostream>
#include <cmath>
#include <vector>

class FormulasDePonto {
public:
    static double distanciaDoisPontos(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

};

class CPF {
    std::string number;

public:
    static bool validate(std::vector<int> number) {
        int sum = 0;
        int rest;
        int first_digit;
        int second_digit;
        int i;

        if (number.size() != 11) {
            return false;
        }

        for (i = 0; i < 9; i++) {
            sum += number[i] * (10 - i);
        }

        rest = sum % 11;

        if (rest < 2) {
            first_digit = 0;
        } else {
            first_digit = 11 - rest;
        }

        sum = 0;

        for (i = 0; i < 10; i++) {
            sum += number[i] * (11 - i);
        }

        rest = sum % 11;

        if (rest < 2) {
            second_digit = 0;
        } else {
            second_digit = 11 - rest;
        }

        if (first_digit == number[9] && second_digit == number[10]) {
            return true;
        } else {
            return false;
        }

    }


    CPF(std::string number) {
        this->number = number;
    }
    void setNumber(std::string number) {
        this->number = number;
    }
    bool isValid() {
        std::vector<int> number;
        int i;
        for (i = 0; i < this->number.size(); i++) {
            number.push_back(this->number[i] - '0');
        }
        return CPF::validate(number);
    }
};


class Tempo {
    int hora;
    int minuto;
    int segundo;

    static void setIntervalo(int &var, int value, int inf, int sup) {
        if (var >= inf && var <= sup) {
            var = value;
        } else { 
            std::cout << "valor invalido" << std::endl;
        }
    }

public:
    Tempo(int h, int m, int s);

    int getHora() const {
        return this->hora;
    }
    int getMinuto() {
        return this->minuto;
    }
    int getSegundo() {
        return this->segundo;
    }

    void setHora(int value) {
        Tempo::setIntervalo(this->hora, value, 0, 23);
    }
    void setMinuto(int value) {
        Tempo::setIntervalo(this->minuto, value, 0, 59);
    }
    void setSegundo(int value) {
        Tempo::setIntervalo(this->segundo, value, 0, 59);
    }
};

int main() {
    Tempo t(0, 0, 0);
    FormulasDePonto::distanciaDoisPontos(0, 0, 1, 1);
    
    CPF::validate(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1});

    CPF cpf("12345678909");
    cpf.isValid();

    std::string number = "1233121123132";
    std::vector<int> number_vector;
    for (int v : number)
        number_vector.push_back(v - '0');
}
