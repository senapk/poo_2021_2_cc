#include <iostream>

//contínuo na memória
#include <vector>
//cada elemento é um bloco de memória separado
#include <list>

//tree
#include <map> //chaves valor ordenado
#include <set> //chaves ordenados
//hash
#include <unordered_set>
#include <unordered_map>

int main() {
    std::map<std::string, int> idades;
    idades["Joao"] = 20;
    idades["Brian"] = 30;
    idades["Ana"] = 40;

    //sobrescrevi o valor
    idades["Joao"] = 50;

    auto it = idades.find("Joao");
    if (it != idades.end()) {
        it->second = 60;
        std::cout << it->second << std::endl;
    }

    for (auto& [nome, idade] : idades) {
        std::cout << nome << " " << idade << std::endl;
    }
}

void main3() {
    std::unordered_map<int, std::string> cadeiras;
    cadeiras[1] = "Maria";
    cadeiras[3] = "João";
    cadeiras[7] = "Tobias";

    //auto [pos, result] = cadeiras.insert(std::make_pair(2, "Pedro"));

    auto it = cadeiras.find(3);
    if (it == cadeiras.end()){
        std::cout << "Não encontrado" << std::endl;
    } else {
        it->second = "MariaAlves";
    }
    // for(auto& pair : cadeiras){
    //     std::cout << pair.first << " " << pair.second << std::endl;
    // }
    for(auto& [chave, valor] : cadeiras){
        std::cout << chave << " " << valor << std::endl;
    }

}

void main2() {
    std::unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    s.insert(7);

    auto it = s.find(1);
    if (it == s.end()) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "found, removendo" << std::endl;
        s.erase(it);
    }

    for (int i : s)
        std::cout << i << std::endl;
}