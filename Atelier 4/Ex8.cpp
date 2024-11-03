// * Exercise 8 : App Fichier

#include <iostream>
#include <cstring>
using namespace std;

class Fichier
{
private :
    char* ptr;
    size_t Size; // * longueur de la zone memoire

public :
    Fichier() : ptr(nullptr), Size(0) {} 
    ~Fichier() 
    { 
        delete[] ptr; 
        ptr = nullptr;
        cout << " Memory freed by destructor " << endl;
    }

    // * Create
    void Creation(size_t size)
    {
        Size = size;
        ptr = new char[Size];
        cout << " Memory of " << Size  << " octets allocated " << endl;
    }

    // * Add
    void Remplit(char value)
    {
        if ( ptr != nullptr )
        {
            memset(ptr, value, Size); 
            cout << " Memory filled with " << value << " " << endl;
        }
        else
        cout << " Memory not allocated " << endl;
    }

    void Display()
    {
        if ( ptr != nullptr)
        {
            cout << " Memory : "<<endl;
            for (int i = 0; i < Size; i++)
            {
                cout << ptr[i] << " ";
            }
            cout << endl;
        }
        else
        cout << " Memory not allocated " << endl;
    }
};

int main()
{
    Fichier* fichier = new Fichier();

    fichier -> Creation(8);
    fichier -> Remplit ( 'f');
    fichier -> Display();

    delete fichier;

    return 0;
}