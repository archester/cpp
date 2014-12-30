#include <iostream>

using namespace std;

template <typename T>
struct no_const
{
    typedef T type;
};

template <typename T>
struct no_const<const T>
{
    typedef T type;
};

int main()
{
    typedef const int cint;

    {
        cint i = 5;
        //i = 2; cant modify const
    }

    {
        no_const<cint>::type i = 5;
        i = 4; // const-ness removed
    }

    return 0;
}

