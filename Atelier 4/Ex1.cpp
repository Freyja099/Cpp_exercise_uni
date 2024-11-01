// * Exercice 1 : Complexe Numbers

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private :  
    double Real, Imaginary;

public:
    // * Constructor
    Complex( double real = 0 , double imaginary = 0 ) : Real(real) , Imaginary(imaginary) {}
    // * Overloaded operators
    Complex operator+(const Complex& other) 
    const{
        return Complex(this-> Real + other.Real , this -> Imaginary + other.Imaginary);
    }
    Complex operator-(const Complex& other)
    const{
        return Complex(this -> Real - other.Real , this -> Imaginary - other.Imaginary);
    }
    bool operator == ( const Complex& other ) 
    const{
        return (this -> Real == other.Real && this -> Imaginary == other.Imaginary) ;
    }
    Complex operator*(const Complex &other)
    const{
        return Complex(this -> Real * other.Real, this -> Imaginary * other.Imaginary);
    }
    Complex operator/(const Complex &other)
    const{
        return Complex(this -> Real / other.Real, this -> Imaginary / other.Imaginary);
    }
    

    int Menu ()
    {
        int op = 0;
        cout << "********************MENU********************" <<endl
             << "1. Sum" << endl
             << "2. Substraction" << endl
             << "3. Equal" << endl
             << "4. Multiplication" << endl
             << "5. Division" << endl;
        return op;

    }

    void Show()
    {
        if ( Imaginary > 0 )
        {
            cout << Real << " + " << Imaginary << "i" << endl;
        }
        else 
            cout << Real << " - " << abs(Imaginary) << "i" << endl;
    }

    void InitialComplex()
    {
        cout << " Enter the real and imaginary parts of the complex number:  "<<endl;
        cin >> Real >> Imaginary ;
        cout << " The complex number you entered is: ";
        Show();
    }
};

int main()
{
    double r1,r2,i1,i2;
    Complex c1(r1,i1), c2(r2,i2) , result ;

    c1.InitialComplex();
    c2.InitialComplex();

    int op = c1.Menu();
    cin >> op ;

    switch (op)
    {
        case 1 : 
        result = c1 + c2;
        break;

        case 2 :
        result = c1 - c2;
        break;

        case 3 :
        result = (c1 == c2)? 1 : 0;
        if (result == 1) 
        cout << "The two complex numbers are equal " << endl;
        else
        cout << "The two complex numbers are not equal " << endl;
        break;

        case 4 :
        result = c1 * c2;
        break;

        case 5 :
        result = c1 / c2;
        break;

        default :
        cout << "Invalid choice " << endl;
        return 0;
    }
    
    if ( op != 3)
    result.Show();

    return 0;

}
