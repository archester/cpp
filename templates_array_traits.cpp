#include <iostream>
#include <unordered_map>

using namespace std;

template<class A>
struct array_traits
{
    static const size_t size = 1;
    static const size_t elem_size = sizeof(A);
};

template<class A, size_t s>
struct array_traits<A[s]>
{
    static_assert(s>0, "sanity");
    static_assert(sizeof(A)>0, "sanity");

    static const size_t size = s;
    static const size_t elem_size = sizeof(A);
};

int main()
{
    typedef int x[20];
    cout << array_traits<x>::size << "\n";
    cout << array_traits<x>::elem_size << "\n";

    cout << array_traits<long long>::size << "\n";
    cout << array_traits<long long>::elem_size << "\n";

    return 0;
}

