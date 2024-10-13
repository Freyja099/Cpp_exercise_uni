#include <iostream>
using namespace std;

int incrementer(int n)
{
    return ++n;
}

void permuter(int* x,int* y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

void permuter2(int &ref_x,int &ref_y)
{
    int temp = ref_y;
    ref_y = ref_x;
    ref_x = temp;
}

int main()
{
    int a, b ;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // * using pointers
    permuter(&a,&b);
    cout << "After swapping: \na =  " << a << endl 
         <<"b =  " << b << endl;

    // * now using ref

    permuter2(a,b);
    cout << "After swapping: \na =  " << a << endl 
         <<"b =  " << b << endl;

    return 0;
}

// ! the permuter2 is working right it shows the first two initial values of a and b because permuter 
// ! has already swapped the two initial values