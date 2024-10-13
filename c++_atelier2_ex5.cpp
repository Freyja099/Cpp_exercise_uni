#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int &ref_a = a; // * reference
    int* p_a = &a; // * pointer
    cout << " les variables : " << a << ", "<< ref_a << ", " << *p_a 
        << "  ; les addresses :  " << p_a  << " , " << &a << " , " << &ref_a
        << "  ; la valeur pointée : " << *p_a  ;
    return 0;
}