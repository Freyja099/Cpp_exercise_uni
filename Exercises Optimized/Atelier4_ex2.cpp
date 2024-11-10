#include <iostream>
using namespace std;

class Animal
{
protected :
    string name;
    int age;
public :
    // Animal( string name_c , int age_c ) : name(name_c) , age(age_c) {} // * Constructor

    // * Set value function we can use it instead of defining a constructor
    /*virtual*/ void set_value (string name , int age )
    {
        this -> name  = name ;
        this -> age = age ;
    }

    // * Afficher function 
     void Afficher () 
    {
        cout << "Name : " << name << '\n'
            << " Age : " << age << endl;
    }

};

class Zebra : public Animal
{
private : 
    // string origin ;
public :
    // Zebra ( string name_c , int age_c , string origin_c) : Animal(name_c , age_c) , origin(origin_c) {}
    /* void Afficher() override
    {
        cout << " Name : " << name << '\n'
            << " Age : " << age << '\n'
            << " origin " << origin << endl;
    }*/
   void Info( string origin )
   {
    cout << " origin : " << endl ;
   }
};

class Dolphin : public Animal 
{
private :
    //string origin ;
public :
    // Dolphin ( string name_c , int age_c , string origin_c) : Animal(name_c , age_c) , origin(origin_c) {}    
    /* void Afficher() override
    {
        cout << "Name : " << name << '\n'
            << "Age : " << age << '\n'
            << "origin " << origin << endl;

    } */

   void Info( string origin )
   {
    cout << " origin : " << endl ;
   }

};

int main()
{
    /* Dolphin dolphin( " Ni " , 7 , "Asia" );
    Zebra zebra( " Nay " , 4 , "Africa" );

    Animal* dolphine_ptr = &dolphin;
    Animal* zebra_ptr = &zebra ;

    dolphine_ptr -> Afficher();
    zebra_ptr -> Afficher(); */

    Dolphin dolphin ;
    dolphin.set_value("Ni", 7);
    dolphin.Afficher();
    dolphin.Info("Asia");

    Zebra zebra;
    zebra.set_value("Nay", 4);
    zebra.Afficher();
    zebra.Info("Africa");

    return 0;
}