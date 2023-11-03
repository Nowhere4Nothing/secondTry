#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Person;
class Contract;

class Company
{    
  private:
    string name;
    string addresss;
    Contract *contr;
  public:    
    explicit Company(string Name="") : name(std::move(Name)), contr(nullptr) {}
    [[nodiscard]] string getName() const { return(name); }
    void setContract(Contract *cn) { contr = cn;}
    [[nodiscard]] Contract *getContract() const { return( contr); }
};

class Person
{  
  private:
    string name;
    Contract *contr;
  public:
    explicit Person(string Name="") : name(std::move(Name)), contr(nullptr) {}
    [[nodiscard]] string getName() const  { return(name);}
    void setContract(Contract *cn) { contr = cn;}
    [[nodiscard]] Contract *getContract() const { return( contr); }
};

class Contract
{    
    Person *pers;
    Company *comp;
    int contNum;
    int duration;
    static float rate;    
  public:       
    Contract( Person* worker, Company* empl, int cN, int dr ) 
    : pers(worker), comp(empl), contNum(cN), duration(dr) 
	 {
	    worker->setContract( this ); // set a link Person->Contract
	    comp->setContract( this );   // set a link Company->Contract
	 }       

    [[nodiscard]] string getPersonName() const { return(pers->getName());}
    [[nodiscard]] string getCompName() const { return(comp->getName()); }
    [[nodiscard]] static float getRate() { return(rate); }
    int getDuration() const { return(duration); }		   
    int getContractNumber() const { return(contNum); }
};

float Contract::rate = 70.00;

int main()
{  
  auto *worker = new Person( "John" );
  auto *company = new Company( "Bell Pty Ltd" );
  auto *company2 = new Company("CodeOrbit studios");

  auto *cont1 = new Contract(worker,company,5247,12 );
  auto *cont2 = new Contract(worker, company2, 6545, 15);

//  delete *company;

  cout <<worker->getName()<<" has a contract number '"
  << worker->getContract()->getContractNumber()
  << "' with " <<worker->getContract()->getCompName()
  << endl;
  
  cout<<"Duration: " << worker->getContract()->getDuration()
  << " months" << endl;
  cout << "Rate: $" << worker->getContract()->getRate()
  << "/hr " <<endl;

cout << company->getContract()->getDuration() << endl;

  return 0;
}

/*
 (a) What concept does it illustrate?
 Object orientated

(b) How are the classes related?
 Association

(c) What happens if either the worker or company is deleted in main, after the Contract is
set up but before the output is displayed?
 Cant delete it as it is being used by another class

(d) What happens if we add an additional company and add a contract between John and
the new company? How would we manage this situation, or the case where a new worker
wants to work for Bell?

if you add an aditional contract it will just display the new contract. Though you can go through the company to get the info too

 */