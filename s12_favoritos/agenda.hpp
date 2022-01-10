#include <iostream>
#include <sstream>
#include <vector>
#include <map> 
#include <memory>

#include "fone.hpp"
#include "contato.hpp"

using namespace std;

//adiciona, recupera, remove contatos, busca
class Agenda {
    map<string, shared_ptr<Contato>> contatos;
    bool alterar_favoritos {true};
public:
    void adicionar(string nome, vector<Fone> fones) {
        auto it = contatos.find(nome); //log n
        if (it != contatos.end()) {
            for (auto fone : fones)
                it->second->addFone(fone);
        } else {
            auto contato = make_shared<Contato>(nome);
            for (auto fone : fones)
                contato->addFone(fone);
            contatos[nome] = contato; //log n
        }
    }

    void remover(string nome) {
        auto it = contatos.find(nome);
        if (it != contatos.end())
            contatos.erase(it);
        alterar_favoritos = true;
    }

    shared_ptr<Contato> pegar(string nome) {
        auto it = contatos.find(nome);
        if (it != contatos.end())
            return it->second;
        throw runtime_error("fail: Contato nao encontrado");
    }

    vector<shared_ptr<Contato>> getFavoritos() {
        static vector<shared_ptr<Contato>> favoritos;
        if (alterar_favoritos) {
            favoritos.clear();
            for (auto& [name, contato] : contatos) {
                if (contato->getFavorito())
                    favoritos.push_back(contato);
            }
            alterar_favoritos = false;
        }
        return favoritos;
    }

    void favoritar(string nome) {
        auto contato = this->pegar(nome);
        if (!contato->getFavorito()) {
            contato->setFavorito(true);
            alterar_favoritos = true;
        }
    }

    void desfavoritar(string nome) {
        auto contato = this->pegar(nome);
        if (contato->getFavorito()) {
            contato->setFavorito(false);
            alterar_favoritos = true;
        }
    }

    vector<shared_ptr<Contato>> buscar(string pattern) {
        vector<shared_ptr<Contato>> result;
        for (auto pair: contatos) {
            string nome = pair.first;
            auto contato = pair.second;
            stringstream ss;
            ss << *contato;
            auto texto = ss.str();
            if (texto.find(pattern) != string::npos)
                result.push_back(contato);
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, Agenda& ag);
};

ostream& operator<<(ostream& os, Agenda& ag) {
    for (auto& c : ag.contatos)
        os << *c.second << endl;
    return os;
}