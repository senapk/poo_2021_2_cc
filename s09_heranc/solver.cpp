#include <iostream>

class Animal {
private:
    bool alive { true };
protected:
    std::string mark { "Animal" };
public:
    Animal() {
        std::cout << mark << " nascendo" << std::endl;
    }
    virtual ~Animal() {
    }
    virtual void eat() {
        std::cout << mark << " eating" << std::endl;
    }
    virtual void die() {
        std::cout << mark << " died" << std::endl;
        alive = false;
    }
    virtual bool isAlive() const {
        return alive;
    }
    friend std::ostream& operator<<(std::ostream& os, const Animal& animal) {
        os << animal.mark << ":" << (animal.alive ? "alive" : "dead");
        return os;
    }
};

class Pet : public Animal {
    std::string name {""};
public:
    Pet(std::string name): name{name} {
        this->mark = "Pet";
        std::cout << name << " nascendo" << std::endl;
    }
    std::string getName() const {
        return name;
    }
    virtual void play() {
        if (this->isAlive()) 
            std::cout << this->name << ": playing" << std::endl;
        else
            std::cout << this->name << ": dead pets dont play" << std::endl;
    }
    virtual void eat() {
        std::cout << this->name << " eating" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Pet& pet) {
        Animal* animal = &pet;
        os << *animal << ":" << pet.name;
        return os;
    }

};

class Cat : public Pet {
    int lives;
public:
    Cat (std::string name): Pet{name}, lives{3} {
        this->mark = "Cat";
    }
    virtual void die() {
        if (this->lives == 0) {
            Animal::die();
        } else {
            this->lives--;
            std::cout << "ainda nao morreu, tente outra vez" << std::endl;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Cat& cat) {
        Pet* pet = &cat;
        os << *pet << ":" << cat.lives;
        return os;
    }
};

int main() {
    Cat cat{"cat"};
    cat.play();

    Animal &animal = cat;
    animal.eat();
    animal.die();
    std::cout << animal << std::endl;

    Pet* pet = &cat;
    pet->eat();
    pet->play();
    pet->die();
    std::cout << *pet << std::endl;
    return 0;
}
