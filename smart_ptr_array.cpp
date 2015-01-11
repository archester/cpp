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
    int _tag;
    static int tag;
    Obj(): _tag(++tag) {}
    Obj(int foo): _tag(++tag) {}
    ~Obj() {std::cout << "deleteing " << _tag << "\n";}
};

int Obj::tag = 0;

void f(std::unique_ptr<Obj>& pobj)
{
    std::cout << pobj.get()->_tag << "\n";
}

int main()
{
    {
        // dynamic array of objectes
        unique_ptr < Obj [] > up(new Obj[2]);
    }

    {
        // array of smart pointers
        unique_ptr<Obj> old_array[2];
        old_array[0].reset(new Obj);
        old_array[1].reset(new Obj);
    }

    {
        // vector of up
        // This won't compile as initializer list always does copy
        // which is not allowed for up
        /*
        std::vector<unique_ptr<Obj>> vec {
             std::move(unique_ptr<Obj>{new Obj()}),
             std::move(unique_ptr<Obj>{new Obj()})
        };
        */
    }

    return 0;
}

