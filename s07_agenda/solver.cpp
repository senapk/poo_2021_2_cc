#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class Pessoa {
private:
    std::string nome;
    int idade;
public:
    Pessoa(std::string nome, int idade) {
        this->nome = nome;
        this->idade = idade;
    }
    std::string getNome() {
        return this->nome;
    }
    int getIdade() {
        return this->idade;
    }
    friend std::ostream& operator<<(std::ostream& os, Pessoa& pessoa){
        os << pessoa.getNome() << "-" << pessoa.getIdade();
        return os;
    }
};

class Lista {
private:
    std::vector<Pessoa> pessoas;

    int procurarPessoa(std::string nome) {
        for (int i = 0; i < pessoas.size(); i++) {
            if (pessoas[i].getNome() == nome) {
                return i;
            }
        }
        return -1;
    }

public:
    Lista() {}
    void addPessoa(Pessoa pessoa) {
        this->pessoas.push_back(pessoa);
        std::sort(pessoas.begin(), pessoas.end(), [](Pessoa pessoa1, Pessoa pessoa2){
            if(pessoa1.getNome() != pessoa2.getNome()) {
                return pessoa1.getNome() < pessoa2.getNome();
            } 
            return pessoa1.getIdade() < pessoa2.getIdade();
        });
    }

    Pessoa* getPessoa(std::string nome) {
        int index = procurarPessoa(nome);
        if (index != -1) {
            return &pessoas[index];
        }
        return nullptr;
    }

    void rmPessoa(std::string nome) {
        int index = procurarPessoa(nome);
        if(index != -1)
            this->pessoas.erase(this->pessoas.begin() + index);
            return;
        }
    }
    std::vector<Pessoa> search(std::string pattern) {
        std::vector<Pessoa> result;
        for (auto& p : this->pessoas) {
            std::stringstream ss;
            ss << p;
            std::string texto_da_pessoa = ss.str();
            if (texto_da_pessoa.find(pattern) != std::string::npos) {
                result.push_back(p);
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, Lista& lista){
        for(int i = 0; i < (int) lista.pessoas.size(); i++) {
            os << lista.pessoas[i] << std::endl;
        }
        return os;
    }
};



int main() {
    Lista lista;
    lista.addPessoa(Pessoa("Joao", 20));
    lista.addPessoa(Pessoa("Maria", 30));
    lista.addPessoa(Pessoa("Jose", 40));
    lista.addPessoa(Pessoa("Claudio", 10));
    lista.addPessoa(Pessoa("Marcelo", 20));
    lista.addPessoa(Pessoa("Tobias", 30));

    Pessoa * claudio = lista.getPessoa("Claudio");
    if(claudio != nullptr) {
        claudio->idade += 1;
    }

    std::vector<int> vet;
    std::cout << vet.front() << std::endl;


    std::cout << lista << std::endl;
}


