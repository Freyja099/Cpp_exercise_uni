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
    cout << " Now let's add 1 to 256 " <<endl;

    array<int,3000000> arr3000000;
    for (int i=0 ; i<3000000 ; i++)
    {
        arr3000000[i] = i+1;
    }

    CallArray(arr3000000, make_index_sequence<3000000>{});

    return 0;
}