#include <iostream>
using namespace std;

int main ()
{
    int t[10];
    
    for (int i = 0 ; i < 10 ; i++ )
    {
        cout << " Entrer la " << i+1 << " valeur du tableau " << endl;
        cin >> t [ i ];
    }

    for ( int i = 0 ; i < 9 ; i++ )
    {
        int min = i;
        for( int j = i + 1 ; j < 10 ; j++ )
        {
            if ( t[ j ] < t [ min ] )
            {
                min = j ;
            }
        }
        int temp = t [ min];
        t [ min ] = t [ i ];
        t [ i ] = temp;
    }    
    for ( int i = 0 ; i < 10 ; i++ )
    {
        cout << " t [ " << i+1 << " ] = " << t[i] << endl;
    }
    return 0;

}
