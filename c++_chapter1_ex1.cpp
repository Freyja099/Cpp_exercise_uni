// TODO : Enter 4 integers a,b,c and d [a,b] , [c,d] and find the intersection of the two intervals

#include <iostream>

using namespace std;
int main()
{
    int a,b,c,d;
    int max=0 , min=0;
    cout << " Enter 4 integers : a,b,c and d (considiring that a < b and c < d) "<<endl;
    cin >> a >> b >> c >> d;

    if(a > b || c > d)    // ! use or "||" not and "&&"
    {   
        cout << "Error!"<<endl;
        return -1;
    }

    max=(a>c)?a:c;
    min=(b>d)?d:b;

    cout << "[" << max << "," << min << "]"<< endl;

    return 0;
}