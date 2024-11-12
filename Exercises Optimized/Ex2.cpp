#include <iostream>
#include <string>
using namespace std;

class Animal
{
    protected :
    string Name;
    int Age;

    public :
    void set_value(string Name , int Age)
    {
        this -> Name = Name;
        this -> Age = Age;
    }

    void Display() const
    {
        cout << " Name  : " << Name << '\n'
            << " Age  : " << Age <<endl;
    }
};

class Zebra : public Animal
{
    private :
    string origin;

    public : 
    void set_value(string Name , int Age , string origin)
    {
        Animal :: set_value(Name , Age) ;
        this -> origin = origin;
    }

    void Display()
    {
        Animal :: Display();
        cout << " Origin : " << origin <<endl;
    }
};

int main()
{
    Animal animal;
    animal.set_value("Animal", 1);
    animal.Display();

    Zebra zebra;
    zebra.set_value("Zebra", 2, "Africa");
    zebra.Display();
    

    return 0;
    
}