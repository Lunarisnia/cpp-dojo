#include <iostream>
#include <string>

using namespace std;
struct Kingdom {
    string name;
};

class Animal {
    public:
        string name;
        string sound;
        Kingdom kingdom;      
    
    void make_sound() {
        std::cout << this->sound << std::endl; 
    }
};

int main() {
    Animal boi;
    boi.name = "Boi";
    boi.sound = "Bork!";
    boi.kingdom.name = "Doggies";

    std::cout << boi.kingdom.name << std::endl;
    boi.make_sound();
    return 0;
}

