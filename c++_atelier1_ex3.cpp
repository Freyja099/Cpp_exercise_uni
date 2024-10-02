//* Exercise 3 Atelier 1:

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << " Enter the number of lines " << endl;
    cin >> n;

    //* the outer loop is the numbers of rows 
    for(int i=0;i<n;i++)
    {
        cout<<"\n";

        //* the first inner loop is to get the space before * to make a triangle
        //* the number of spaces should decrease in each row (i) e.g : in the first row i=0
        //* saying for example n=4 we need 3 spaces which means (n-1)
        //* still with n=4 this time the second row i=1 we need 2 spaces which means n-1-1 and that's how we get the condition where to stop...
        for(int k=0;k<n-i-1;k++)
        {
            cout<<" ";
        }

        //* the second inner loop is to print * but our triangle is symmetric 
        //* if it wasn't we could put the condition i+1 since we initialized i to zero 
        //* or initialize i to 1 and in that case the loop should stop when j is bigger than i
        //* but now we have to multiply i by 2 to get the symmetric triangle
        for(int j=0;j< 2*i+1 ;j++)
            {   
                cout<<"*";
            }
    }
    
    return 0;
}

//* End of exercise 