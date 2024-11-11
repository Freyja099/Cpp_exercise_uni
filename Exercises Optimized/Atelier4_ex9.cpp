#include <iostream>
#include <list>
using namespace std;

struct Element
{
    int value;
    Element *next;
    // * Constructor for struct
    Element (int value_c) : value(value_c) , next(nullptr) {}
};

class List 
{
private :
    Element *head;

public :
    // * Constructor
    List() : head(nullptr){}
    List(const List& other) : head(nullptr)
    {
        Element *current = other.head;
        
    }

    // * Destructor
    ~List()
    {
        Element *current = head;
        while (current != nullptr)
        {
            Element *temp = current ;
            current = current -> next ;
            delete temp;
        }
    }

    void Add(int value)
    {
        Element * newElement = new Element(value);
        newElement -> next = head;
        head = newElement;
    }

    void Delete()
    {
        if (head != nullptr)
        {
            Element *temp = head;
            head = head -> next ;
            delete temp;
        }
        else
        {
            cout << "La liste est vide " <<endl;
        }
        
    }

    void Afficher()
    {
        if (head == nullptr)
        {
            cout << "la liste est vide"<<endl;
        }
        else 
        {
            Element *current = head;
            while(current != nullptr)
            {
                cout << current -> value << " ";
                current = current -> next;
            }
            cout << endl;
        }
    }
    // * Inverser
    void Inverser() // * We can use reverse function by including list library
    {
        Element *previous = nullptr;
        Element *current = head;
        Element *next = nullptr;

        while (current != nullptr)
        {
            next = current -> next;
            current -> next = previous;
            previous = current ;
            current = next;
        }
        head = previous ;
    }
};

int main ()
{
    List l;
    l.Afficher();
    l.Add(1);
    l.Add(4);
    l.Afficher();
    l.Delete();
    l.Afficher();
    l.Add(6);
    l.Add(7);
    l.Afficher();
    l.Inverser();
    l.Afficher();

    return 0;
}


    