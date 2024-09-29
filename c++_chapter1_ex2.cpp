// TODO : write a program that calculate sin(x) with an approximation of 0.0001

#include <iostream>

using namespace std;

// * let's create first a function that calculates the power

float power(float base, float exponent)
{
    float pow=1;

    if(exponent<0) 
    return -1;
    if(base == 0 && exponent == 0)
    return -1;

    for(int i=0 ; i<exponent ; i++)
    {
        pow *= base;
    }

    return pow;
}

// * Now let's create a function that calculates factorials

int factorial(int n)
{
    int fact = n;
    if( n < 0 ) 
    return -1;
    if (n == 0) 
    fact = 1;

    for (int i=1;i<n;i++) // ? does i start from 0 (I doubt it) does it end when i <= n ?
    {
        fact  = fact * (n-i);
    }
    return fact;
}
int main()
{
    float x;
    int n=0;
    float division = 0;
    float numerator = 0;
    float denominator = 1;
    float sum = 0;
    cout <<"Enter x:" << endl;
    cin >> x;
    

    do
    {
        numerator= power(-1,n) * power(x,(2*n+1));
        denominator = factorial(2*n+1);
        division = numerator / denominator;
        n++;
        sum += division;
    }while(division > 0.0001);
    

    cout <<"sin( " << x << " )= "<< sum <<endl;

    return 0;
}