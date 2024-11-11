#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Pile
{
private :
    vector <int> elements;

public :
    // * Constructor by default
    Pile(){}
    // * Constructor parameterized
    Pile(int value) 
    {
        elements.push_back(value);
    }
    // or
    //Pile(int value) : elements(1 , value) {}

    // * Copy constructor
    Pile(const Pile& other) : elements(other.elements) {}
    // * Destructor
    ~Pile() {}

    // * Empiler
    void push(int value )
    {
        elements.push_back(value);
    }

    // * Depiler
    int pop()
    {
        if (elements.empty())
        {
            throw out_of_range("The stack is empty");
        }

        auto it = elements.rbegin() ;
        int topValue = *it ;

        elements.pop_back();
        return topValue ;
    }

    // * Display
    void Display()
    {
        for( auto it : elements)
        cout << it << " " ;
        cout <<endl;
    }
};

int main()
{
    Pile p1;
    Pile p2;
    p1.push(3);
    p1.push(4);
    p1.push(2);
    p1.Display();
    cout << endl ;
    p2.push(5);
    p2.push(3);
    p2.Display();
    cout << endl ;
    p1.pop();
    p1.Display();

    cin.get();
}