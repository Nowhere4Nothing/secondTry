#include<iostream>
#include<string>
#include <utility>
using namespace std;

class Cat
{
private:
   string name;
   string breed;
   int age;
   static constexpr double licenseFee = 10;

public:
    Cat() : name(), breed(), age() {}

    Cat(string n, string b, int a) : name(std::move(n)), breed(std::move(b)), age(a) {}

    string getName() {
        return name;
    };

    string getBreed() {
        return breed;
    };

    int getAge() {
        return age;
    };

    static double getLiscenceFee(){
        return licenseFee;
    }

   void setCatData(string, string, int);
   void showCat();
   void showCatAddress();

   ~Cat();
};

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

void showCatOtherWay(Cat &cat) {

        cout << "Cat: " << cat.getName() << " is a " << cat.getBreed() << endl;
        cout << "The cat's age is " << cat.getAge() << endl;
        cout << "License fee: $" << Cat::getLiscenceFee() << endl << endl;
}

void Cat::showCatAddress()
{
    cout << "Cat " << name << " is in the address: " << &name << endl;
    cout << "Cat breed: " << breed << " is in the address: " << &breed << endl;
    cout << "The cat's age: " << age  << " is in the address: "<< &age << endl << endl;

}


void showCatAddressOther(Cat(&cat))
{
    cout << "The Cat " << cat.getName() << " object is in the address: " << &cat << endl;
    cout << "This is just calling the object using getters and setters " << endl << endl;
}

int main()
{
    cout << "---------------------------Program Initiated-----------------------------" << endl <<endl;

    Cat myCat;
    myCat.setCatData("Tigger", "Fluffy unit", 3);
    myCat.showCat();
    myCat.showCatAddress();

     Cat theirCat("Bear", "Tabby", 1);
     showCatOtherWay(theirCat);
     showCatAddressOther(theirCat);

     Cat theirCat2 = theirCat;
     cout << "Copy Cat" << endl;
     theirCat2.showCatAddress();

    showCatOtherWay(theirCat2);
    showCatAddressOther(theirCat2);

    cout << "---------------------------Program terminated-----------------------------" << endl <<endl;
}

Cat::~Cat() {
    cout << "Cat " << name <<  " has been deleted" << endl << endl;
}