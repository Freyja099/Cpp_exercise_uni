// * Exercise 4 : Vecteur3d

#include <iostream>
#include <cmath>
using namespace std;

class Vecteur3D
{
private :
    float x , y , z;
public :
    // * Constructor
    Vecteur3D(float x = 0, float y = 0, float z = 0) 
    : x(x), y(y), z(z) {}
    
    // * Display composants 
    void display() const
    {
        cout << "(" << x << ", " << y << ", " << z << ")" 
             << endl;  
    }

    // * Sum of two vectors
    Vecteur3D somme (const Vecteur3D& other) const
    {
        return Vecteur3D(x + other.x , y + other.y , z + other.z);
    }

    // * Dot product of two vectors
    float produit (const Vecteur3D& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    // * Verification
    bool coincide ( const Vecteur3D& other ) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    // * Norme
    float norme() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    // * normax = norme max ; by value
    Vecteur3D normax (const Vecteur3D& other) 
    {
        return (this->norme() >= other.norme()) ? *this : other;
    }

    // * normax = norme max ; by addresse
    const Vecteur3D* normax ( const Vecteur3D* other ) 
    {
        return ( this-> norme() > other -> norme()) ? this : other ;
    }

    // * normax = norme max ; by reference

    const Vecteur3D& normax(const Vecteur3D& other ,bool)
    {
        return (this->norme() > other.norme()) ? *this : other;
    }

};

// * test

    int main()
    {
        Vecteur3D vect1(1,0,3);
        Vecteur3D vect2(4,0,0);

        cout << " Affichage : "<<endl;
        vect1.display();
        vect2.display();

        cout << " Somme : "<<endl;
        Vecteur3D somme = vect1.somme(vect2);
        somme.display();

        cout << " Produit scalaire : "<<endl;
        cout << vect1.produit(vect2) << endl;

        cout << " Coincidence : "<<endl;
        cout << (vect1.coincide(vect2)? "YES" : "NO") << endl;

        cout << " Norme : "<<endl;
        cout << vect1.norme() << endl;
        cout << vect2.norme() << endl;

        Vecteur3D norme_max_value = vect1.normax(vect2);
        cout << " Norme max value : "<<endl;
        norme_max_value.display();

        const Vecteur3D* norme_max_ref = vect1.normax(&vect2);
        cout << " Norme max reference : "<<endl;
        norme_max_ref->display();

        const Vecteur3D& norme_max_add = vect1.normax(vect2 , true);
        cout << " Norme max addresse : "<<endl;
        norme_max_add.display();

        system(" pause > nul ");
    }