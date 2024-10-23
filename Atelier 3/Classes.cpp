#include <iostream>
using namespace std;

class Voiture
{
private :
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

public :

    // * Constructor by default
    Voiture() 
    {
        marque = "" ;
        modele = "" ;
        annee = 0 ;
        kilometrage = 0.0 ;
        vitesse = 0.0 ;
    }
    
    // * Constructor with parameters
    Voiture(string marque_c , string modele_c , int annee_c , float kilometrage_c , float vitesse_c ) 
    {
        marque = marque_c ;
        modele = modele_c ;
        annee = annee_c ;
        kilometrage = kilometrage_c ;
        vitesse = vitesse_c ;
    }

    // * Methods :

    float accelerer( float valeur)
    {
        vitesse += valeur;
        return vitesse ;
    }

    float freiner (float valeur)
    {
        if ( vitesse - valeur >= 0)
        {
            vitesse -= valeur;
        }
        else
        {
            vitesse = 0;
        }
        return vitesse;
    }

    void afficherInfo()
    {
        cout<< "Informations sur la voiture : " << "\n"
            << " Marque : " << marque << "\n"
            << " Modele : " << modele << "\n"
            << " Annee : " << annee << "\n"
            << " Kilometrage : " << kilometrage << "\n"
            << " Vitesse : " << vitesse <<endl;
    }

    float avancer(float distance)
    {
        return kilometrage += distance;
    }

    // * Destructor 
    ~Voiture() 
    {
        cout << " La voiture " << marque << ", " << modele << " est détruite." << endl;
    }
};

// * test :

int main()
{
    Voiture voiture1("BMW" , "850i" , 1991 ,120000 , 250);
    cout << voiture1.avancer(100) << endl;
    cout << "*******************************************" << endl;
    cout << voiture1.freiner(30) << endl;
    cout << "*******************************************" << endl;
    voiture1.afficherInfo();
    cout << "*******************************************" << endl;
    cout << voiture1.accelerer(40) << endl;
    cout << "*******************************************" << endl;
    return 0 ;
}