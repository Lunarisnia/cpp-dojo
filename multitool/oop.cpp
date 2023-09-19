#include <iostream>
#include <string>

class Animal
{
private:
    std::string name;

public:
    void setName(std::string n)
    {
        name = n;
    }

    virtual void makeSound()
    {
        std::cout << "My sound is unimplemented, so.... BORK!" << std::endl;
    }

    void command(std::string p1)
    {
        std::cout << "Wheeee " << p1 << std::endl;
    }

    void command(std::string p1, std::string p2)
    {
        std::cout << "Whoooo " << p1 << " " << p2 << std::endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Bark!" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Kekekkekeke!" << std::endl;
    }
};

int main()
{
    // Dog boi;
    // boi.setName("Boi");
    // boi.makeSound();

    Animal *animals[2] = {new Dog, new Cat};
    animals[0]->makeSound();
    animals[1]->makeSound();

    animals[0]->command("Bloo");
    animals[1]->command("Bloo", "Peee");
    delete animals[0];
    delete animals[1];
    return 0;
}