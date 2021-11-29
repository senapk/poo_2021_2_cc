#include <iostream>

class Fone {
};

class Contato {
    std::string id;
    friend std::ostream& operator<<(std::ostream&, const Contato&);
};

class Agenda {
    std::map<std::string, Contato> contatos;


    void adicionar(Contato c) {
        auto it = contatos.find(c.id);
        if (it == contatos.end()) {
            //se ja existir, não sobrescreve
            //auto [it, res] = contatos.insert(std::make_pair(c.id, c));
            contatos[c.id] = c;
        } else {
            for (Fone fone : c.fones)
                it->second.addFone(fone);
        }
        //se não existe cria
    }

    void remove(std::string id) {
        auto it = contatos.find(id);
        if (it != contatos.end()) {
            contatos.erase(it);
        } else {
            std::cout << "Contato não encontrado" << std::endl;
        }
    }

    std::vector<Contato> search(std::pattern) {
        std::vector<Contato> res;
        for (auto& [nome, contato] : contatos) {
            std::stringstream ss;
            ss << contato;
            auto texto = ss.str();
            if (texto.find(pattern) != std::string::npos) {
                res.push_back(contato);
            }
        }
        return res;
    }

};