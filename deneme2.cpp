#include <iostream>

class Animal {
public:
    virtual ~Animal() {}   // polymorphic class
};

class Dog : public Animal {
public:
    void bark() { std::cout << "Dog\n"; }
};

int main() {
    Animal* a = new Dog();

    Dog* d = dynamic_cast<Dog*>(a);

    if (d)
        d->bark();
    else
        std::cout << "Cast başarısız\n";

    Animal* c = new Animal();

    Dog* e = dynamic_cast<Dog*>(c);

    if (e == nullptr)
        std::cout << "Cast başarısız\n";
}