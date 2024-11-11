#include <iostream>

using namespace std;

class Fichier
{
private :
    char *P ;
    int Longueur ;
public :
    // * Constructor by default
    Fichier() : P(nullptr) , Longueur(0) {}

    // * Constructor copy
    Fichier(const Fichier& other) : P( new char[other.Longueur]), Longueur(other.Longueur) 
    {
        for (int i = 0 ; i < Longueur ; i++)
        {
            P[i] = other.P[i] ;
        }
    }

    // * Constructor parameterized
    Fichier( int longueur) :Longueur(longueur)
    {
        P = new char[longueur];
    }

    // * Destructor
    ~Fichier()
    {
        delete [] P ;
    }

    void Creation()
    {
        if ( P!= nullptr)
        {
            cout << " Memory already allocated " <<endl;
            return;
        }
        else 
        {
            P = new char [Longueur];

        }
    }

    void Remplit()
    {
        if (P == nullptr)
        {
            cout << " Memory not allocated" <<endl;
            return;
        }
        else
        {
            for (int i = 0 ; i < Longueur -1 ; i++)
            {
                P[i] = '9';
            }
            P[Longueur - 1] = '\0';
        }
    }

    void Affiche() const
    {
        if ( P != nullptr)
        {
            cout << P <<endl;
        }
        else 
        cout << " Pointer NULL "<< endl;
    }

};

int main()
{
    Fichier f(4);
    f.Creation();
    f.Remplit();
    f.Affiche();

    return 0;
}