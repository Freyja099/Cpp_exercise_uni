// * Exercise 3: Person

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string FirstName;
    string LastName;
    string Birth;

public:
    Person ( string firstname , string lastname , string birth) : 
    FirstName(firstname), LastName(lastname), Birth(birth){}
    virtual void Affiche() const
    {
        cout << " First name: " << FirstName <<endl
            <<" Last name: " << LastName << endl
            <<" Birth: " << Birth << endl;
    }
};

class Employee : public Person
{
protected:
    double Salary;

public : 
    Employee ( string firstname , string lastname , string birth , double salary ) :
    Person(firstname , lastname , birth) , Salary(salary) {}

    void Affiche() const
    {
        Person::Affiche();
        cout <<" Salary: " << Salary << " $" <<endl;
    }

};

class Chef : public Employee
{
protected:
    string Service;

public : 
    Chef ( string firstname , string lastname , string birth , double salary ,string service ) :
    Employee(firstname , lastname , birth , salary), Service(service) {}

    void Affiche() const
    {
        Employee::Affiche();
        cout << "Service: " << Service <<endl;
    }

};

class Directeur : public Chef
{
private : 
    string Societe;

public : 
    Directeur ( string firstname , string lastname , string birth , double salary ,string service , string societe) :
    Chef(firstname , lastname , birth , salary, service) , Societe (societe){}

    void Affiche() const
    {
        Chef ::Affiche();
        cout << " Societe : " << Societe <<endl;
    }

};

// * Test : 

int main()
{
    Person person("Jane" , "Ni" , "02/02/1990");
    Employee employee("Larry" , "Kell", "04/12/1976", 30000.0);
    Chef chef("Marry" , "Devine", "12/07/1954", 23400.0, "Manager");
    Directeur directeur("Toto" , "Wolf", "16/06/1980", 999999.0, "Director", "Mercedes");

    person.Affiche();
    cout << "--------------------------------------------------------------" << endl;
    employee.Affiche();
    cout << "--------------------------------------------------------------" << endl;
    chef.Affiche();
    cout << "--------------------------------------------------------------" << endl;
    directeur.Affiche();

    return 0;
}