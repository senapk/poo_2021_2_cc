#include <list>
#include <vector>
#include <iostream>


int main() {

    std::vector<int> v(5, 7);
    v[2] = 5;

    v.push_back(5);
    v.pop_back();

    v.erase(v.begin() + 10);

    std::list<int> l(6, 3);
    l.push_back(5);
    l.pop_back();
    l.push_front(5);
    l.pop_front();

    l.erase(std::next(l.begin(), 10));

}