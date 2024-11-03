// * Exercise 5 : Call function using static variable

#include <iostream>
using namespace std;

class Test 
{
private :
    static int counter;
public :
    //int getCounter(return counter;)
    void call ()
    {
        counter++;
    }
    static void Display()
    {
        cout << " This function was called  " << counter << "  times "<<endl;
    }

};

int Test  :: counter = 0;

int main()
{
    Test t1;
    t1.call();
    t1.call();
    t1.call();

    Test :: Display();

    return 0;
}