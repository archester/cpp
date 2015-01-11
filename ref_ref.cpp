#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>

using std::unique_ptr;

struct Obj
{

    Obj() { std::cout << "default ctor\n"; }
    Obj(const Obj&)  { std::cout << "copy ctor\n"; }
    Obj(const Obj&&) { std::cout << "move ctor\n"; }
    ~Obj() {std::cout << "dtor\n";}
};

void f(Obj&& o)
{

}

int main()
{
    {
        // error: can't bind lvalue

        /*
        Obj o;
        f(o);
        */

    }

    {
        Obj o;
        f(std::move(o));
    }


    {
        // error: fwd valid only in template

        /*
        Obj o;
        f(std::forward(o));
        */
    }

    return 0;
}

