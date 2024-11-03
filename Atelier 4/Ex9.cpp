// * Exercise 9 : List 

#include <iostream>
using namespace std;

class Element 
{
private :
    int Value;
    Element* next;

public :
    Element(int value) : Value(value), next(nullptr) {}
    int getValue()
    {
        return Value;
    }

    Element* getNext()
    {
        return next;
    }

    void setNext(Element* next)
    {
        this->next = next;
    }
};

class List
{
private:
    Element* head;

public:
    List() : head(nullptr) {}

    ~List()
    {
        while(head != nullptr)
        {
            Element* temp = head;
            head = head->getNext();
            delete temp;
        }
    }

    void add(int value)
    {
        Element* newElement = new Element (value);
        newElement -> setNext(head);
        head = newElement;
    }

    void Delete()
    {
        if (head != nullptr )
        {
            Element* deleteElement = head;
            head = head -> getNext();
            delete deleteElement;
        }
        else
        cout << " List empty "<<endl;
    }

    void Display()
    {
        Element* current = head;
        cout << " List : "<<endl;
        if (current == nullptr)
        {
            cout << " List empty " <<endl;
            return;
        }
        
        while (current != nullptr)
        {
            cout << current -> getValue() << endl ;
            current = current -> getNext();
        }
    }
};

int main ()
{
    List list ;

    list.add(3);
    list.add(5);
    list.add(7);
    list.add(9);

    list.Display();

    list.Delete();

    return 0;
}