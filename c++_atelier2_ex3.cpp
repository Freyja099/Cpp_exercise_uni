#include <iostream>
using namespace std;

// * Method 1 
/*
int main()
{
    int max,min;
    int array [10];
    for(int i = 0 ; i<10 ; i++ ) // * loop to enter the values
    {
        cout << " enter the " << i+1 << "  element " <<endl;
        cin >> array [i];
    }
    max = array [0];
    min = array [0];
    for( int j = 0 ; j<10 ; j++ ) // *  iterate over all the element and find min and max
    {
        if (array[j] > max)
        max = array [j];
        if (array[j] < min)
        min = array [j];
    }
    cout << " The maximum is : " << max << endl;
    cout << " The minimum is : " << min << endl;
    return 0;
}
*/
// * Method 2   

// * we can get the memory address of a variable by using the & operator 
// * A pointer however, is a variable that stores the memory address as its value.
// * A pointer variable points to a data type (like int or string) of the same type, and is created with the * operator.
/*
string food = "Pizza";  
string* ptr = &food;    
cout << food << "\n";
cout << &food << "\n";
cout << ptr << 
*/

// * Method 2

int main()
{
    int max,min;
    int array [10];
    for(int i = 0 ; i<10 ; i++ ) // * loop to enter the values
    {
        cout << " enter the " << i+1 << "  element " <<endl;
        cin >> array [i];
    }
    max = *array;
    min = *array;
    for ( int *ptr = array +1 ; ptr < array + 10 ; ptr++)
    {
        if (*ptr > max)
        max = *ptr;
        if (*ptr < min)
        min = *ptr;
    }
    
    cout << " The maximum is : " << max << endl;
    cout << " The minimum is : " << min << endl;
    return 0;
}
