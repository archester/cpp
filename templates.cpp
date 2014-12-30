#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <cassert>

template <unsigned i>
struct Fibb
{
    static const unsigned value = Fibb<i-2>::value +Fibb<i-2>::value;
};

template<>
struct Fibb<0>
{
    static const unsigned value = 1;
};

template<>
struct Fibb<1>
{
    static const unsigned value = 1;
};


template <bool b>
struct my_static_assert
{
    typedef char arr[b ? 1 : -1];
};

template <typename T>
struct has_x_static
{
    typedef char yes[1];
    typedef char no[2];

    template<typename C>
    static yes& test(typename C::x);

    template <typename>
    static no& test(...);

    static const bool value = (sizeof(test<T>(0)) == sizeof(yes));
};

class C{};

class D
{
public:
    typedef int x;
};

int main()
{
    my_static_assert< true > f;

    std::cout << has_x_static<C>::value << "\n";
    std::cout << has_x_static<D>::value << "\n";

    std::cout << Fibb<2>::value << "\n";
   return 0;
}

