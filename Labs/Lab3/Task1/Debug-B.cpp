#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Hat {
  private:
    string type;
    char size; // S, M, L

  public:
   Hat(string, char);
    void display();
};

Hat::Hat(string _type, char _size) : type (std::move(_type)), size (_size) {}

void Hat::display()
{
    cout << "Hat type   : " << type << endl;
    cout << "Hat size   : " << size << endl << endl;
}

class Person {
  private:
    string name;
    unsigned int idNum;

public:
    Hat myHat;
    Person(string, unsigned int ,string, char);
    void display();
    ~Person();
};

Person::Person(string _name, unsigned int _idNum, string hattype, char hat_size)
        : name(std::move(_name)), idNum(_idNum), myHat(std:: move(hattype),hat_size) {}

Person::~Person() {
    cout << "Person destroyed" << name;

    cout << endl;
};

void Person::display()
{
        cout << "Given name : " << name << endl;
        cout << "Id. number : " << idNum << endl;
}

int main()
{
	Person personA("Alice",12321,"Beret",'M');
	Person personB("Bob",2324,"Trilby",'S');
    personA.display();
	personA.myHat.display();
	personB.display();
    personB.myHat.display();
}
