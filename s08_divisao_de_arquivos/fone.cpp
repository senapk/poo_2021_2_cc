#include <iostream>
#include "fone.hpp"
//fone.cpp
Fone::Fone(std::string number): number(number) {
}
std::string Fone::getNumber() {
    return number;
}
