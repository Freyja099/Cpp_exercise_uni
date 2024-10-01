//* Atelier 1 : Exercise 2 

#include <iostream>
using namespace std;

main()
{
    // TODO cas 1

    int n=10, p=5, q=10, r ;
    r = n == (p = q) ;
    cout << "A : n = " << n << " p = " << p << " q = " << q << " r = " << r << "\n" ;

    //* A : n = 10 p = 10 q = 10 r = 1

    //* Explanation : 
    //* = is the assignment operator which assigns a value to a variable , == is the equality operator which compares two values 
    //* and returns true (1) if the values are equal or false (0) if they are not
    //* The evaluation happens from right to left 
    //* p=q => p will get the value of q => p=10 and q=10
    //* n==(p=q) => this is true because n=10
    //* and finally r=1 because it store the value of the comparaison
    //! however this won't change the value of n whether it was right or wrong because the == operator won't modify the value,
    //! in fact if r didn't exist like n==(p=q) n will equal to 10 and the result of the comparaison will be 
    //! discarded because there's no variable like r to store the result
    //! other thing if we r was initialized let's say r = 6; this won't change anything r won't keep its value or take n value 
    //! r will equal to either 0 or 1 depends on the comparaison result



    // TODO cas 2

    n=10; p=5; q=10;

    n = p = q = 5 ;
    n += p += q ; 
    cout <<"B: n = " << n << " p = " << p << " q = " << q << "\n";

    //* B: n = 15 p = 10 q = 5

    //* Explanation:
    //* first all n,p and q has the value 5
    //* The evaluation happens from right to left 
    //* q = 5
    //* p += q means p = p + q => p = 10
    //* n += (p+q) means n = n + (p+q) => 15

    // TODO cas 3

    n=10; p=5; q=10;

    q = n > p ? n++ : p++ ; 
    cout << "C : n = " << n << " p = " << p << " q = " << q << "\n" ;

    //* C: n = 11 p = 5 q = 10

    //* Explanation :
    //* Here we use what we call a ternory operator : q equal to n + 1 if n > p  
    //* otherwise (n < q) q equal to p + 1

    // TODO cas 4

    n=10; p=5; q=10;

    n = 5 ; p = 2 ;
    q = ++n == 6 && ++p == 3 ;
    cout << "D : n = " << n << " p = " << p << " q = " << q << "\n" ;

    //* D : n = 6 p = 3 q = 1

    //* Explanation : 
    //* first line we changed the values of n and p
    //* ++n means n now equal to n+1 it's called pre-increment, This means that the variable n is incremented 
    //* before it is used in the expression since n = 6 now that means q is true and it equals to 1
    //* Same as before for ++p but the result of the comparaison won't show because we don't have another variable to do that like before

}


// * End of exercise 2