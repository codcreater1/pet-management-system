#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pet {
    string nm; // pet name
    int age;
    string kind; // pet type
public:
    Pet(string n, int a, string k) {
        nm = n;  // init stuff
        age = a;
        kind = k;
    }
    virtual void display() {
        cout << "Name: " << nm << ", Age: " << age << ", Type: " << kind << endl; // show pet info
    }
    virtual void makeSound() {
        cout << "no sound..." << endl; // default if no override
    }
    int getAge() { return age; }
    string getKind() { return kind; }
};

class Dog : public Pet {
public:
    Dog(string n, int a) : Pet(n, a, "Dog") {}
    void makeSound() override {
        cout << "woofff!" << endl; // dog's noise
    }
};

class Cat : public Pet {
public:
    Cat(string n, int a) : Pet(n, a, "Cat") {}
    void makeSound() override {
        cout << "meeeoooww" << endl; // cat's noise
    }
};

int countPets(const vector<Pet*>& v) {
    return v.size(); // how many pets total
}

Pet* oldestPet(vector<Pet*>& v) {
    if (v.empty()) return nullptr; // no pets
    Pet* oldest = v[0]; // start with first
    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i]->getAge() > oldest->getAge())
            oldest = v[i]; // update oldest if found older
    }
    return oldest;
}

void addPetByUser(vector<Pet*>& pets) {
    string n, k;
    int a;
    cout << "Enter pet name: ";
    cin >> n; // get name
    cout << "Enter pet age: ";
    cin >> a;
    cout << "Enter pet type (dog/cat/other): ";
    cin >> k;

    if (k == "dog" || k == "Dog")
        pets.push_back(new Dog(n, a)); // dog object
    else if (k == "cat" || k == "Cat")
        pets.push_back(new Cat(n, a)); // cat object
    else
        pets.push_back(new Pet(n, a, k)); // generic pet

    cout << "Pet added!\n";
}

int main() {
    vector<Pet*> pets;
    // starting pets
    pets.push_back(new Dog("Buddy", 3));
    pets.push_back(new Cat("Queen", 5));
    pets.push_back(new Pet("Oldie", 10, "Cat"));

    char choice;
    do {
        cout << "Add new pet? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            addPetByUser(pets); // user input pet
        }
    } while (choice == 'y' || choice == 'Y');

    cout << "\nAll pets:\n";
    for (int i = 0; i < (int)pets.size(); i++) {
        pets[i]->display(); // show pet
        pets[i]->makeSound(); // sound
    }

    Pet* oldPet = oldestPet(pets);
    if (oldPet) {
        cout << "\nOldest pet is:\n";
        oldPet->display(); // show oldest
    }

    cout << "\nTotal pets: " << countPets(pets) << endl;

    // clear memory
    for (int i = 0; i < (int)pets.size(); i++) {
        delete pets[i];
    }
    pets.clear();

    return 0;
}
