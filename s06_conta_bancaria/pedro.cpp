#include <iostream>
#include <vector>
#include <string>
#include <memory>


class Pessoa {
public:
    std::string id;
    int idade;
    Pessoa(std::string id, int idade) : id(id), idade(idade) {}

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
        os << p.id << ":" << p.idade;
        return os;
    }
};

class Cinema { //agregação
private:
    std::vector<std::shared_ptr<Pessoa>> cadeiras;
public:

    Cinema(int lotacao): cadeiras(lotacao, nullptr) {
    }

    int procurarPessoa(std::string id) {
        for (int i = 0; i < (int) cadeiras.size(); i++)
            if (cadeiras[i] != nullptr && cadeiras[i]->id == id)
                return i;
        return -1;
    }

    void adicionarPessoa(std::shared_ptr<Pessoa> pessoa, int indice) {
        if (indice < 0 || indice >= (int) cadeiras.size()) {
            std::cout << "Indice invalido" << std::endl;
            return;
        }
        if (cadeiras[indice] != nullptr) {
            std::cout << "Cadeira ocupada" << std::endl;
            return;
        }
        if(this->procurarPessoa(pessoa->id) != -1) {
            std::cout << "Pessoa ja esta no cinema" << std::endl;
            return;
        }
        cadeiras[indice] = pessoa;
    }

    std::shared_ptr<Pessoa> removerPessoa(std::string id) {
        int indice = procurarPessoa(id);
        if (indice == -1) {
            std::cout << "Pessoa nao encontrada" << std::endl;
            return nullptr;
        }
        return std::exchange(cadeiras[indice], nullptr);
    }

    friend std::ostream& operator<<(std::ostream& os, const Cinema& c) {
        os << "[ ";
        for (auto cadeira : c.cadeiras) {
            if (cadeira == nullptr)
                os << "- ";
            else
                os << *cadeira << " ";
        }
        os << "]";
        return os;
    }
};

#include <tuple>
#include <sstream>

template <typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    std::apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

void show_help() {
    std::cout << "Comandos:" << std::endl;
    std::cout << "  help" << std::endl;
    std::cout << "  init <qtd>" << std::endl;
    std::cout << "  add <id> <idade> <indice>" << std::endl;
    std::cout << "  rm <id>" << std::endl;
    std::cout << "  show" << std::endl;
    std::cout << "  end" << std::endl;
}

int main(){
    Cinema cinema(0);
    show_help();
    while(true) {
        std::string line{}, cmd{};
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        std::cout << "$" << line << '\n';
        if (cmd == "end") {
            break;
        } else if (cmd == "help") {
            show_help();
        } else if (cmd == "init") {
            auto [qtd] = parse<int>(ss);
            cinema = Cinema(qtd);
        } else if (cmd == "show") {
            std::cout << cinema << '\n';
        } else if (cmd == "add") {
            auto [nome, idade, indice] = parse<std::string, int, int>(ss);
            cinema.adicionarPessoa(std::make_shared<Pessoa>(nome, idade), indice);
        } else if (cmd == "rm") {
            auto [nome] = parse<std::string>(ss);
            cinema.removerPessoa(nome);
        } else {
            std::cout << "fail: comando invalido" << '\n';
        }
    }
    return 0;
}
