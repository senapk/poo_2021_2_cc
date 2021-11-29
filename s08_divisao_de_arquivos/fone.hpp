#pragma once

#include <iostream>
//fone.hpp
//declaração
class Fone {
    std::string number;
public:
    Fone(std::string number);
    std::string getNumber();
};