#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    string species;
public:
    Animal(string n, int a, string s) : name(n), age(a), species(s) {}
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << ", Species: " << species << endl;
    }
    string getSpecies() { return species; }
};

class Hyena : public Animal {
public:
    Hyena(string n, int a) : Animal(n, a, "Hyena") {}
};

class Lion : public Animal {
public:
    Lion(string n, int a) : Animal(n, a, "Lion") {}
};

class Tiger : public Animal {
public:
    Tiger(string n, int a) : Animal(n, a, "Tiger") {}
};

class Bear : public Animal {
public:
    Bear(string n, int a) : Animal(n, a, "Bear") {}
};

int main() {

    vector<Animal*> animals;


    map<string, int> speciesCount;


    animals.push_back(new Hyena("Scar", 5));
    animals.push_back(new Lion("Simba", 3));
    animals.push_back(new Tiger("Shere Khan", 7));
    animals.push_back(new Bear("Baloo", 10));


    for (Animal* a : animals) {
        speciesCount[a->getSpecies()]++;
    }


    for (Animal* a : animals) {
        a->display();
    }

    cout << "\nSpecies Count:\n";
    for (const auto& pair : speciesCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    for (Animal* a : animals) {
        delete a;
    }
    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.