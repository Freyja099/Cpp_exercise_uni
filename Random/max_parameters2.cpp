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
    cout << " Now let's try 256" <<endl;

    array<int,256> arr256;
    for (int i=0 ; i<200 ; i++)
    {
        arr256[i] = i+1;
    }

    CallArray(arr256, make_index_sequence<256>{});

    return 0;
}
