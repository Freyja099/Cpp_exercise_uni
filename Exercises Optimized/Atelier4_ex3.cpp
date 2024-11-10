#include <iostream>
#include <string>

using namespace std;

class Person 
{
protected :
    string FirstName ;
    string LastName ;
    string Birth ;

public :
    // * Default Contructor 
    Person(){}
    // * Constructor with parameters
    Person( string firstname , string lastname , string birth ) : FirstName( firstname ), LastName( lastname) , Birth( birth ) {}
    // * Copy constructor
    Person ( const Person& other) : FirstName(other.FirstName) , LastName(other.LastName) , Birth(other.Birth) {}
    // * Destructor
    ~ Person(){}

    // * Display
    virtual void Display () const
    {
        cout << "First name: " << FirstName << endl
             << "Last name: " << LastName << endl
             << "Birth: " << Birth << endl;
    }

};

class Employee : public Person
{
protected:
    float Salary ;
public :
    // * Default Constructor
    Employee(){}
    // * Constructor with parameters
    Employee (string firstname , string lastname , string birth , float salary) : Person (firstname , lastname , birth) , Salary(salary) {}
    // * Copy constructor
    Employee (const Employee& other) : Person(other) , Salary(other.Salary) {}
    // * Destructor 
    ~Employee(){}

    // * Display 
    void Display() const override
    {
        Person :: Display();
        cout << "Salary: " << Salary << endl;
    }

};

class Chef : public Employee
{
protected : 
    string Service ;
public : 
    // * Default constructor
    Chef(){}
    // * Constructor with parameters
    Chef ( string firstname , string lastname , string birth , float salary , string service) :
    Employee (firstname , lastname , birth , salary), Service(service) {}
    // * Copy constructor
    Chef (const Chef& other) : Employee(other) , Service(other.Service) {}
    // * Destructor
    ~Chef(){}

    // * Display 
    void Display() const override
    {
        Employee :: Display() ;
        cout << "Service : " << Service <<endl; 
    }
};

class Director : public Chef 
{
private :
    string Society ;

public : 
    // * Constructor by default
    Director(){}
    // * Constructor with parameters
    Director (string firstname , string lastname , string birth , float salary , string service , string society) : 
    Chef (firstname , lastname , birth , salary , service) , Society(society) {}
    // * Copy Constructor 
    Director (const Director& other) : Chef(other) , Society ( other.Society ) {}
    // * Destructor
    ~Director(){}

    // * Display 
    void Display() const override
    {
        Chef :: Display();
        cout << "Society : " << Society << endl;
    }

};

int main()
{
    Person p("Nia" , "Lee" , " 09/11/2001");
    Employee e("Nia" , "Lee" , " 09/11/2001" , 8000 ) ;
    Chef c("Nia" , "Lee" , " 09/11/2001 " , 8000 , "Design");
    Director d("Nia" , "Lee" , " 09/11/2001" , 8000 ,"Design" ,"Apple");

    p.Display();
    e.Display();
    c.Display();
    d.Display();

    cin.get();
}
