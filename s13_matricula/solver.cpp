#include <iostream>
#include <map>
#include <vector>
#include <sstream>

//aluno.hpp
class Disciplina;
class Aluno {
    std::string nome;
    std::map<std::string, Disciplina*> disciplinas;
public:
    Aluno(std::string nome) : nome(nome) {}
    void addDisciplina(Disciplina * disciplina);
    void rmDisciplina(std::string nome);

    std::string getNome(){return nome; }
    friend std::ostream& operator<<(std::ostream& os, const Aluno& aluno);
};

//disciplina.hpp
//include <aluno.hpp>
class Disciplina {
    std::string nome;
    std::map<std::string, Aluno*> alunos;
public:
    Disciplina(std::string nome) : nome(nome) {}
    void addAluno(Aluno * aluno);
    void rmAluno(std::string nome);
    std::string getNome(){return nome;}
    friend std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina);
};




//aluno.cpp
//include disciplina.hpp
void Aluno::addDisciplina(Disciplina * disciplina) {
    auto key = disciplina->getNome();
    if(disciplinas.find(key) != disciplinas.end())
        return;
    this->disciplinas[key] = disciplina;
    disciplina->addAluno(this);
}

void Aluno::rmDisciplina(std::string nome) {
    auto it = disciplinas.find(nome);
    if(it == disciplinas.end())
        return;
    Disciplina * disciplina = it->second;
    this->disciplinas.erase(it);
    disciplina->rmAluno(this->nome);
}

std::ostream& operator<<(std::ostream& os, const Aluno& aluno) {
    os << "Aluno: " << aluno.nome << std::endl;
    for(auto& [key, value] : aluno.disciplinas)
        os << " " << value->getNome();
    return os;
}

//disciplina.cpp
void Disciplina::addAluno(Aluno * aluno) {
    auto key = aluno->getNome();
    if(alunos.find(key) != alunos.end())
        return;
    this->alunos[key] = aluno;
    aluno->addDisciplina(this);
}

void Disciplina::rmAluno(std::string nome) {
    auto it = alunos.find(nome);
    if(it == alunos.end())
        return;
    Aluno * aluno = it->second;
    this->alunos.erase(it);
    aluno->rmDisciplina(this->nome);
}

std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina) {
    os << "Disciplina: " << disciplina.nome << std::endl;
    for(auto& [key, value] : disciplina.alunos)
        os << " " << value->getNome();
    return os;
}

class Sistema {
    std::map<std::string, Aluno*> alunos;
    std::map<std::string, Disciplina*> disciplinas;
public:
    Sistema() {}
    void addAluno(std::string nome);
    void rmAluno(std::string nome);
    void addDisciplina(std::string nome);
    void rmDisciplina(std::string nome);
    void vincular(std::string nomeAluno, std::string nomeDisciplina);
};


int main() {
    Sistema sistema;
    sistema.addAluno("aluno1");
    sistema.addAluno("aluno2");
    sistema.addAluno("aluno3");

    sistema.addDisciplina("disciplina1");
    sistema.addDisciplina("disciplina2");
    sistema.addDisciplina("disciplina3");

    sistema.vincular("aluno1", "disciplina1");
    sistema.vincular("aluno1", "disciplina2");



}