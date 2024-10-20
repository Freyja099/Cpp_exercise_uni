#include <iostream>
#include <array>

using namespace std;

template <typename... Args>
void function(Args... Args_n)
{
    cout << sizeof...(Args_n)<< "parameters" << endl;

}

template <typename t, size_t n , size_t...i>
void CallArray(const array < t , n > & arr , index_sequence <i...>)
{
    function(arr[i]...);
}

int main()
{
    cout << " Let's try first with a number smaller than 256 " <<endl;

    array<int,200> arr200;
    for (int i=0 ; i<200 ; i++)
    {
        arr200[i] = i+1;
    }

    CallArray(arr200, make_index_sequence<200>{});

    return 0;
}
