#include <iostream>
using namespace std;
int n;
int even()
{
    if (n % 2 == 0)
    {
        cout << " il est pair "<<endl;
        return 1;
    }
    return 0;
}

int MultipleOf3()
{
    if(n % 3 == 0)
    {
        cout << " il est multiple de 3 " << endl;
        return 1;
    }
    return 0;
}

int main()
{
    cout << " Donnez un entier : " ;
    cin >> n ;
    int f1= even();
    int f2= MultipleOf3();
    if ( f1 && f2)
    {
        cout << " il est divisible par 6 "<<endl;
    }
    return 0;

}