// * Complex Number

#include <iostream>
#include <cmath>

using namespace std;

template <typename T , typename U>

class ComplexNumber
{
private :
    T Real ;
    U Imaginary ;
public :
    // * Constructors
    // * Constructor by default
    ComplexNumber() : Real(0) , Imaginary(0) {}

    // * Constructor with arguments
    ComplexNumber(T real , U imaginary) : Real (real) , Imaginary (imaginary) {}

    // * Constructor : Deep copy constructor
    ComplexNumber(const ComplexNumber& other) : Real(other.Real) , Imaginary(other.Imaginary) {}

    // * Operator Overloading
    ComplexNumber operator+(const ComplexNumber& other) const 
    {
        return ComplexNumber(this -> Real + other.Real , this -> Imaginary + other.Imaginary);
    }
    ComplexNumber operator-(const ComplexNumber& other) const
    {
        return ComplexNumber(this -> Real - other.Real , this -> Imaginary - other.Imaginary);
    }
    ComplexNumber operator*(const ComplexNumber& other) const
    {
        // * Here we take an example first to see the whole picture : (a+ib) * (c+id) = ac + (bc+ad)i - bd 
        return ComplexNumber((this -> Real * other.Real - this -> Imaginary * other.Imaginary) , (this -> Real * other.Imaginary +
         this -> Imaginary * other.Real));
    }
    ComplexNumber<double , double> operator/(const ComplexNumber& other) const 
    {
        // * Here we take an example first to see the whole picture : ( a+ib ) / (c + id) = (a+ib) * (c - id) / (c² + d²)
        // * = [(ac + bd) + i(bc - ad)] / (c² + d²) ;
        // * now it's clear that the real part is (ac + bd)/ (c² + d²) and the imaginary part is (bc - ad) / (c² + d²)

        return ComplexNumber<double , double>
        ( 
          ( static_cast<double>(this -> Real * other.Real) + static_cast<double>(this -> Imaginary * other.Imaginary) ) 
          / static_cast<double> ( pow(other.Real , 2) + pow(other.Imaginary, 2) ) 
           ,
          (static_cast<double> (this -> Imaginary * other.Real) - static_cast<double>(this -> Real * other.Imaginary) ) 
          / static_cast<double>( pow(other.Real , 2) + pow(other.Imaginary, 2) )
        );
    }
    bool operator==(const ComplexNumber& other) const
    {
        return ( this -> Real == other.Real && this -> Imaginary == other.Imaginary);
    }
    bool operator!=(const ComplexNumber& other) const
    {
        return (this -> Real != other.Real || this -> Imaginary != other.Imaginary);
    }

    // * Here we have to define first "modulus"
    double modulus () const
    {
        return sqrt (pow(Real , 2) + pow(Imaginary , 2));
    }

    bool operator<(const ComplexNumber& other) const
    {
        return  this -> modulus() < other.modulus();
    }

    bool operator>(const ComplexNumber& other) const
    {
        return this -> modulus() > other.modulus();
    }
    bool operator<=(const ComplexNumber& other) const
    {
        return this -> modulus() <= other.modulus();
    }
    bool operator>=(const ComplexNumber& other) const
    {
        return this -> modulus() >= other.modulus();
    }

    // * Display function
    void Display() 
    {
        if (Imaginary < 0)
        {
            cout << "The complex is : " << '\n'
                 << Real << " - " << (-1)*Imaginary << " i " <<endl;
        }
        else 
        {
            cout << "The complex is : " << '\n'
                 << Real << " + " << Imaginary << " i " <<endl;
        }
    }

        // * Or we can use 
    /*  if (Imaginary < 0)
        {
            cout << "The complex is : " << '\n'
                 << Real << " - " << abs(Imaginary)<< " i " <<endl;
        } 
    */

        // * Destructor

        ~ComplexNumber(){}

        // * Or we can use
        /* ~ComplexNumber()
        {
            cout << " The constructor was deleted " << endl;
        }
        */
};


int main()
{
    ComplexNumber <int , int> c1(1 , 2);
    ComplexNumber <int , int> c2(3 , -4);

    c1.Display();
    c2.Display();

    ComplexNumber <int , int> c3 = c1 + c2;
    ComplexNumber <int , int> c4 = c1 - c2;
    ComplexNumber <int , int> c5 = c1 * c2;
    ComplexNumber <double , double> c6 = c1 / c2;
    ComplexNumber <double , double> c7 = c2 / c1;

    c3.Display();
    c4.Display();
    c5.Display();
    c6.Display();
    c7.Display();

    cout << " the == : " << (c1 == c2 ? "True" : "False") << endl;
    cout << " the != : " << (c1 != c2 ? "True" : "False") <<endl;
    cout << " the > : " << (c1 > c2 ? "True" : "False") <<endl;
    cout << " the < : " << (c1 < c2 ? "True" : "False") << endl;
    cout << " the >= : " << (c1 >= c2 ? "True" : "False") << endl;
    cout << " the <= : " << (c1 <= c2 ? "True" : "False") << endl;

    return 0;
}

// ! Issues I had 
// ! Operator overloading : return a ComplexNumber( ... , ... )
// ! In declaration of object declare their type <int , int >
// ! Division : I needed to switch the c1 and c2 to double, use static_cast<double>: By casting the terms to double, we ensure floating-point division, which avoids truncation.
// ! Fix multiplication and division
// ! In operator overloading that contains comparison it's boolean