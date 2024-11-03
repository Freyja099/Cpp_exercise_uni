// * Exercise 6 : main

#include <iostream>
#include "Ex6.h"
using namespace std;

int main()
{
    Point point(1.2 , 2.3);

    cout << " Point : " ;
    point.Affiche();

    cout << "Point apres deplacement :";
    point.Deplace(0.2 , 1);
    point.Affiche();

    return 0;
}