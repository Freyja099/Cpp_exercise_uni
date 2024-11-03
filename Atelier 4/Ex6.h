// * Exercise 6 : Declaration of the class

#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float x , y ;

public:
    // * Constructor
    Point ( float x, float y ) : x(x) , y(y) {}

    // * Deplacement
    void Deplace ( float dx , float dy);

    // * Display
    void Affiche () const;
};

#endif 