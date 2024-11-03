// * Exercise 7 : pile 

#include <iostream>
#include <vector>
using namespace std;

class Pile
{
private :
    vector <int> elements;

public :
    // * Constructor by default already exist

    // * Empiler element sur la pile
    void push (int value)
    {
        elements.push_back(value);
    }

    // * Dépiler element de la pile

    int pop()
    {
        if (elements.empty())
        {
            cout << "Erreur : pile vide" << endl;
            exit(1);
        }

        int value = elements.back();
        elements.pop_back();
        return value;
    }

    // * Vérifier si la pile est vide
    bool isEmpty()
    {
        return elements.empty();
    }
};

int main()
{
    Pile pile1;

    pile1.push(1);
    pile1.push(2);
    pile1.push(3);
    pile1.push(4);
    pile1.push(5);

    cout << " La pile apres depiler : " << endl;
    while (!pile1.isEmpty())
    {
        cout << pile1.pop() << endl;
    }
    
    return 0;
}