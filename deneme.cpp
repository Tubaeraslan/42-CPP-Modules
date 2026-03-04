#include <iostream>

class Animal {
public:
    void speak() { std::cout << "Animal\n"; }
};

class Dog : public Animal {
public:
    void bark() { std::cout << "Dog\n"; }
};

int main() {
    Animal* a = new Dog();

    Dog* d = static_cast<Dog*>(a);
    d->bark();   // Çalışır

    Animal* e = new Animal();
    Dog* c = static_cast<Dog*>(e);
    c->bark();   // 💥 Undefined behavior
}