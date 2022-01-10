#include <iostream>
#include <sstream>
#include <vector>
#include <map> 
#include <memory>

#include "fone.hpp"
#include "contato.hpp"
#include "agenda.hpp"
#include "auxiliar.hpp"
using namespace std;

vector<Fone> parseFones(stringstream& ss) {
    vector<Fone> foneList;
    string token;
    while (ss >> token) {
        vector<string> parts = split(token, ':');
        foneList.push_back(Fone(parts[0], parts[1]));
    }
    return foneList;
}

int main(){
    Agenda agenda;
    while(true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << '\n';
        try {
            if (cmd == "end") {
                break;
            } else if (cmd == "add") {//add nome label:fone label:fone
                string nome = read<string>(ss);
                auto fones = parseFones(ss);
                agenda.adicionar(nome, fones);
            } else if (cmd == "rm") {//add nome
                agenda.remover(read<string>(ss));
            } else if (cmd == "get") {//add nome
                cout << *agenda.pegar(read<string>(ss)) << endl;
            } else if (cmd == "fav") {//add nome
                agenda.pegar(read<string>(ss))->setFavorito(true);
            } else if (cmd == "unfav") {//add nome
                agenda.pegar(read<string>(ss))->setFavorito(false);
            } else if (cmd == "show") {//add nome
                cout << agenda;
            } else if (cmd == "favs") {//add nome
                cout << vec_ptr_to_string(agenda.getFavoritos(), '\n');
            } else if (cmd == "search") {//add nome
                cout << vec_ptr_to_string(agenda.buscar(read<string>(ss)), '\n');
            } else {
                cout << "fail: comando invalido" << endl;
            }
        } catch (runtime_error& e) {
            cout << "fail: " << e.what() << endl;
        }
    }
    return 0;
}



/*
add ana oi:123 tim:543 vivo:543
add jose tim:123 vivo:123
add ana tim:123 vivo:123
add bruno casa:143
show
fav bruno
show


*/