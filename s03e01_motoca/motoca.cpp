#include <iostream>
#include <sstream>

struct Pessoa {
    std::string nome; //atributo
    int idade;

    Pessoa(std::string nome = "", int idade = 0) { //construtor default
        this->nome = nome;
        this->idade = idade;
    }

    Pessoa(int idade) : Pessoa("", idade) {
    }

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
        os << "Nome: " << p.nome << " Idade: " << p.idade;
        return os;
    }
};


struct Motoca {
    Pessoa* pessoa {nullptr}; //agregação
    int tempo {0};
    int potencia {1};
    Motoca(int pot): potencia {pot} {
    }


    bool inserirPessoa(Pessoa * p) {
        if (this->pessoa != nullptr) {
            std::cout << "Motoca cheia" << std::endl;
            return false;
        }
        this->pessoa = p;
        return true;
    }

    std::string buzinar() {
        return "P" + std::string(this->potencia, 'e') + "m";
    }

    Pessoa * removerPessoa() {
        Pessoa * p = this->pessoa;
        this->pessoa = nullptr;
        return p;
    }

    void comprarTempo(int tempo) {
        this->tempo += tempo;
    }

    bool dirigir(int tempo) {
        if (this->pessoa == nullptr) {
            std::cout << "nao tem gente pra dirigir" << std::endl;
            return false;
        }
        if (tempo > this->tempo) {
            std::cout << "só conseguiu dirigir " << this->tempo << " minutos" << std::endl;
            this->tempo = 0;
            return true;
        }
        std::cout << "conseguiu dirigir " << this->tempo << " minutos" << std::endl;
        this->tempo -= tempo;
    }

    friend std::ostream& operator<<(std::ostream& os, const Motoca& m) {
        os << "T: " << m.tempo << " P: " << m.potencia;
        os << "[" << (m.pessoa == nullptr ? "vazio" : m.pessoa->nome) << "]";
        return os;
    }
};

int main() {
    Motoca motoca(1);
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            int pot = 0;
            ss >> pot;
            motoca = Motoca(pot);
        } else if (cmd == "show") {
            std::cout << motoca << "\n";
        } else if (cmd == "inserir") {
            std::string nome {};
            int idade {};
            ss >> nome >> idade;
            Pessoa * pessoa = new Pessoa(nome, idade);  //heap
            if(!motoca.inserirPessoa(pessoa))
                delete pessoa;
        } else if (cmd == "retirar") {
            Pessoa* pessoa = motoca.removerPessoa();
            if (pessoa != nullptr) {
                delete pessoa; //heap
            }
        } else {
            std::cout << "Comando nao existe\n";
        }
    }
}

