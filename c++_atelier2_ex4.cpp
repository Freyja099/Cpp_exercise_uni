#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int size ;
    cout << " Entre la taille du tableau : " ;
    cin >> size;
    int* tab = new int[size];
    for ( int i = 0 ; i < size ; i++)
    {
        cout << " Enter the " << i+1 << " value of the tab " << endl;
        cin >> tab[ i ];        // or *(tab + i)
    }
    
    int *tab2 = new int[size];
    for (int j = 0 ; j < size ; j++ )
    {
        tab2[j] = pow(tab[j],2);
    }
    delete[] tab;
    cout << " The square of the numbers are " << endl;
    for (int j = 0 ; j < size ; j++ )
    {
        cout << tab2[j] << endl ;
    }
    delete[] tab2;
    tab = nullptr;
    tab2 = nullptr;
    return 0;
}

// * Static memory - stack, allocated at compile time 
// * compile time is when your program is converted from cpp into machine code
// * Dynamic memory - heap, allocated at run time need to be cleaned up
// * heap is larger than stack 

// * to create an array : int array [capacity] = { elements }; this one is an array on stack , 
// * the elements can be lower than the capacity but not over it because static give you a fixed capacity 
// * instead we can declare an int called a capacity and to allocate a heap memory we have to use a pointer
// * int* array = new int[capacity]; new is a key word 
// * to free the memory we use : delete[] array ;
// * but the pointer still pointing to the same memory address, we have to change that too 
// * by making it = nullptr , which means it points to no pointer that way 