// * Exercise 2 : Animal Class

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected :
    string Name;
    int Age;
public : 
    void set_value( string name , int age )
    {
        Name = name;
        Age = age;
    }

    virtual void Info() 
    {
        cout << " Supplementary information :" <<endl;
    }

    virtual void Introduce()
    {
        cout << " The Animal" <<endl
        << "Name : "<< Name <<endl
        << "Age :"  << Age <<" years old"<< endl;
    }
};

class Zebra : public Animal 
{
private :
    string country;
public :
    void Introduce ()
    {
        cout << "Zebra : " <<endl
        << "Name : "<< Name <<endl
        << "Age :" << Age <<" years old"<< endl;
    }

    void Info ()
    {
        cout << Name << " is from Botswana "<<endl;
    }
};

class Dolphin: public Animal 
{
private :
    string country;
public :
    void Introduce ()
    {
        cout << " Dolphin : " <<endl
        << "Name : "<< Name <<endl
        << "Age :" << Age <<" years old"<< endl;
    }

    void Info ()
    {
        cout << Name << " is from Pacific Ocean "<<endl;
    }
};

int main()
{
    Zebra zebra ;
    Dolphin dolphin;

    zebra.set_value("Nia", 3);
    dolphin.set_value("Lee", 5);
    Animal* a1 = &zebra;
    Animal* a2 = &dolphin;   

    a1 ->Introduce();
    a1 ->Info();

    cout << "*****************************************"<<endl;

    a2 ->Introduce();
    a2 ->Info();

    return 0; 
       
}