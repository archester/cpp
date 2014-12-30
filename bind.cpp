#include <iostream>
#include <functional>

int f(int x, int y)
{
    std::cout << x << "," << y << " ";
    return x+y;
}

struct Obj
{
    int x;
    int f(int x, int y)
    {
        std::cout << x << "," << y << " ";
        return this->x + x + y;
    }
};

int main()
{
    using namespace std::placeholders;

    auto f1 = std::bind(f,1,2);
    std::cout << f1() << "\n"; // prints 1,2 3

    auto f2 = std::bind(f,std::placeholders::_1, 3);
    std::cout << f2(2) << "\n"; // prints 2,3 5

    std::function<int(int,int)> f3 = f;
    f3(3,3); // prints 3,3

    std::function<int(int)> f4 = std::bind(f, 5, std::placeholders::_1);
    f4(3); // prints 5,3

    Obj o{3};
    auto f5 = std::bind(&Obj::f, _1, _2, _3);
    std::cout << f5(o,2,2); // prints 5,3 7

    return 0;
}

