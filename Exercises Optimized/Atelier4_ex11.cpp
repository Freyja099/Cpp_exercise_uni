#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm> // * To sort the median
using namespace std;

class Traitement
{
private :
    vector <int> vect;

public :
    // * Default constructor
    Traitement(){}

    // * Parameterized constructor
    Traitement (const vector <int> &vect_c) : vect(vect_c) {}
    // * Copy constructor
    Traitement (const Traitement& other) : vect(other.vect) {}
    // * Destructor
    ~Traitement() {}

    // * Methode Initialise
    void Initialiser()
    {
        int num;
        string num_string;

        vect.clear();
        // * To check if the elements are == 0 or odds
        cout << "Enter elements that are even and not nul : " <<endl;


        for (int i = 0 ; i < 15 ; ) // * Increment inside the loop
        {
            // * We'll suppose that it will be a string first 
            getline(cin,num_string);
            
            try
            {
                    num = stoi(num_string);
                    if (num != 0 && num % 2 == 0)
                    {
                        vect.push_back(num);
                        i++ ;
                    }
                    else 
                    cout << " The number can't be accepted " <<endl;
            }
            catch (const invalid_argument& ia)
            {
                cout << " Invalid argument please try an integer" <<endl;
            }
            catch (const out_of_range& oor)
            {
                cout << " The number is out of range please try smaller one" <<endl;
            }
       
            
        }
        
    }

    // * Methode Afficher recursivity
    void show(int temp = 0) 
    {
        if (temp >= vect.size())             
        // ! Don't use sizeof(vect) because will return the size of the vector object itself, not the number of elements in it.
        {
            return;
        }
        
        
        cout << vect[temp] <<endl;
        show(temp + 1);
    }

    friend double moyenne(const Traitement& t) ;
    friend double median (const Traitement& t);
};

double moyenne(const Traitement& t) 
{
    double sum = 0.0;
    for (auto it :t.vect )
    {
        sum += it;
    }
    sum = sum / 15;  //* or sum / t.vect.size()
    return sum;
}

double median (const Traitement& t)
{
    vector <int> temp;
    temp = t.vect;
    sort(temp.begin() , temp.end());

    int size_temp = temp.size();
    if (size_temp % 2 == 0)
    {
        return  (temp [(size_temp/ 2)  -1 ] +  temp [size_temp / 2]) / 2.0 ;
    }

    else 
    return (temp [size_temp / 2]) ;
}

int main ()
{
    Traitement t;
    t.Initialiser();
    cout << "Votre vecteur est : " << endl;
    t.show();

    cout << "La moyenne est : " << moyenne(t) << endl;
    cout << "La mediane est : " << median(t) << endl;

}