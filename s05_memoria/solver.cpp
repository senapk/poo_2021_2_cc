#include <iostream>
#include <memory>

struct Person {
    std::string name;
    int age;
    Person(std::string name, int age) : name(name), age(age) {}

    friend os& operator<<(os& os, const Person& person) {
        os << "name: " << person.name << ", age: " << person.age;
        return os;
    }
};


int main() {

    std::shared_ptr<Person> p1(new Person("John", 20));
    std::shared_ptr<Person> p2 = make_shared<Person>("John", 20);
    auto p3 = make_shared<Person>("John", 20);
    auto p4 = std::shared_ptr<Person>(new Person("John", 20));


    std::shared_ptr<int> q {nullptr};
    {
        std::shared_ptr<Person> p4 = p3;
        std::shared_ptr<int> p(new int(42));

        std::cout << p << std::endl; //500
        std::cout << *p << std::endl; //5
        std::cout << p.use_count() << std::endl;

        q = p;
        std::cout << p.use_count() << std::endl;//2
    }
    *q = 50;
    std::cout << q.use_count() << std::endl;//1
    std::cout << q << std::endl; //500
    std::cout << *q << std::endl; //5
}