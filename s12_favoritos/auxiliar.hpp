#include <iostream>
#include <sstream>
#include <vector>
#include <map> 
#include <memory>

#include "fone.hpp"
#include "contato.hpp"
#include "agenda.hpp"
using namespace std;


//oi:123 tim:543 vivo:543212

vector<Fone> parseFones(stringstream& ss) {
    vector<Fone> foneList;
    string label, numero, token;
    while (ss >> token) {
        stringstream ss2(token);
        getline(ss2, label, ':');
        getline(ss2, numero);
        foneList.push_back(Fone(label, numero));
    }
    return foneList;
}

template <typename T>
string to_string(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

template <typename T>
T read(stringstream& ss) {
    T t;
    ss >> t;
    return t;
}

vector<string> split(string s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delim))
        result.push_back(token);
    return result;
}

template <typename T>
string to_string(vector<T> v, char delim) {
    stringstream ss;
    for (auto t : v)
        ss << t << delim;
    return ss.str();
}

template <typename T>
string to_string_ptr(vector<T> v, char delim) {
    stringstream ss;
    for (auto t : v)
        ss << *t << delim;
    return ss.str();
}

template <typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    std::apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

template <typename T>
vector<T> values(map<string, T>& m) {
    vector<T> result;
    for (auto pair : m)
        result.push_back(pair.second);
    return result;
}