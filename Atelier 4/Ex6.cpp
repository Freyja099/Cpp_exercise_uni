// * Exercise 6 : Define Class

#include <iostream>
#include "Ex6.h"
using namespace std;

Point :: Point ( float x, float y ) : x(x) , y(y) {}

void Point :: Deplace ( float dx , float dy)
{
    x += dx;
    y += dy;
}

void Point :: Affiche () const
{
    cout << " ( " << x << "," << y << " ) " << endl;
}