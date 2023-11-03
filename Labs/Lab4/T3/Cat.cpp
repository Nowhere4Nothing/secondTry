#include<iostream>
#include<string>
#include <utility>
#include <vector>

using namespace std;

class Animal;
class Animal {
protected:
    string name;
    int age;
    vector<Animal*> animals;

public:
    Animal() : name(), age() {}

    Animal(string an, int aa) : name(std::move(an)), age(aa) {};

   virtual void displayAnimal() const =0;

//   {
//        cout << "Animal name is: " << name << endl;
//        cout << "Animal age is: " << age << endl << endl;
//    }

    ~Animal();
};

class Cat : public Animal
{
private:
   string type;
   string breed;
   static constexpr double licenseFee = 10;

public:
    Cat() : Animal(), type(), breed() {}

    Cat(string cName, int cAge, string cType, string cBreed) :
    Animal(std::move(cName), cAge), type(std::move(cType)), breed(std::move(cBreed)) {}

    void displayAnimal() const override {
        cout << "Type of animal: " << type << endl;
        cout << "Name of cat: " << name << endl;
        cout << "Age of cat: " << age << endl;
        cout << "Type of breed: " << breed << endl;
        cout << "Licence fee cost: " << licenseFee << endl;
    }

    static void animalSound() {
        cout << "Meow" << endl << endl;
    }

   void setCatData(string, string, int);
   void showCat();
};

class Dog : public Animal {
private:
    string type;
    string breed;
    static constexpr double licenseFee = 20;

public:
    Dog() : Animal(), type(), breed() {}

    Dog (string dname, int dage, string dType, string dBreed) :
    Animal(std::move(dname), dage), type(std::move(dType)), breed(std::move(dBreed)) {}

    void displayAnimal() const override {
        cout << "Type of animal: " << type << endl;
        cout << "name of Dog: " << name << endl;
        cout << "Age of dog: " << age << endl;
        cout << "Type of breed: " << breed << endl;
        cout << "Licence fee cost: " << licenseFee << endl;
    }

    static void animalSound() {
        cout << "Woof" << endl << endl;
    }
};

int main()
{
    cout << "---------------------------Program initiated -----------------------------" << endl;

    cout << "This is diplayed using normal setter methods Cat::setData" << endl;
    Cat firstCreation;
     firstCreation.setCatData("Tigger", "Fluffy unit", 3);
     firstCreation.showCat();

//     Animal myAnimal("Mammal", 5);
//     myAnimal.displayAnimal();

     Cat myCat("Sammi", 2, "Cat", "Void");
     myCat.displayAnimal();
     myCat.animalSound();

     Dog myDog("Charlie", 3, "Dog", "Golden retriever");
     myDog.displayAnimal();
     myDog.animalSound();

     vector<Animal*> animals;
     animals.push_back(&myCat);
     animals.push_back(&myDog);

     cout << "This is now displayed using a vector!" << endl;
     for (const Animal* animalPtr : animals) {
         animalPtr->displayAnimal();
         cout << endl;
     }

    cout << "---------------------------Program Terminated -----------------------------" << endl;
}

void Cat::setCatData(string catName, string catBreed, int catAge)
{
    name = std::move(catName);
    breed = std::move(catBreed);
    age = catAge;
}

void Cat::showCat()
{
    cout << "Cat: " << name << " is a " << breed << endl;
    cout << "The cat's age is " << age << endl;
    cout << "License fee: $" << licenseFee << endl << endl;
}

Animal::~Animal() {
    cout << "Animal '"  << name <<"' has been deleted" << endl;
}