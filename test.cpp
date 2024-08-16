#include <iostream>
#include <string>

// Kelas dasar (superclass)
class Animal {
protected:
    std::string name;

public:
    // Konstruktor
    Animal(std::string name) : name(name) {}

    // Metode untuk mendapatkan nama hewan
    std::string getName() {
        return name;
    }

    // Metode virtual untuk suara hewan (polimorfisme)
    virtual void makeSound() {
        std::cout << name << " makes a sound!" << std::endl;
    }

    // Metode virtual untuk informasi hewan
    virtual void info() {
        std::cout << "This is an animal named " << name << "." << std::endl;
    }
};

// Kelas turunan (subclass) dari Animal
class Dog : public Animal {
public:
    // Konstruktor
    Dog(std::string name) : Animal(name) {}

    // Override metode makeSound
    void makeSound() override {
        std::cout << name << " barks!" << std::endl;
    }

    // Override metode info
    void info() override {
        std::cout << name << " is a dog." << std::endl;
    }
};

// Kelas turunan lain dari Animal
class Cat : public Animal {
public:
    // Konstruktor
    Cat(std::string name) : Animal(name) {}

    // Override metode makeSound
    void makeSound() override {
        std::cout << name << " meows!" << std::endl;
    }

    // Override metode info
    void info() override {
        std::cout << name << " is a cat." << std::endl;
    }
};

int main() {
    // Membuat objek dari kelas Dog dan Cat
    Dog myDog("Rex");
    Cat myCat("Whiskers");

    // Menampilkan informasi dan suara dari setiap objek
    myDog.info();       // Output: Rex is a dog.
    myDog.makeSound();  // Output: Rex barks!

    myCat.info();       // Output: Whiskers is a cat.
    myCat.makeSound();  // Output: Whiskers meows!

    // Demonstrasi polimorfisme menggunakan pointer ke kelas dasar
    Animal* animal1 = &myDog;
    Animal* animal2 = &myCat;

    animal1->info();       // Output: Rex is a dog.
    animal1->makeSound();  // Output: Rex barks!

    animal2->info();       // Output: Whiskers is a cat.
    animal2->makeSound();  // Output: Whiskers meows!

    return 0;
}
