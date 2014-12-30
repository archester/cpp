#include <iostream>
#include <memory>

using namespace std;

struct parent
{
    ~parent()
    {
        std::cout << "~parent()\n";
    }
};

struct child: public parent
{
    ~child()
    {
        std::cout << "~child()\n";
    }
};

int main()
{
    std::cout << "1)\n";
    {
        parent* p = new child();
        delete p;
    }

    std::cout << "2)\n";
    {
        shared_ptr<parent> p ( new child() );
    }

    std::cout << "3)\n";
    {
        shared_ptr<parent> sp;
        parent* p = new child();
        sp.reset(p);
    } // only parent destructor this time


    std::cout << "4)\n";
    {
        shared_ptr<parent> sp;
        child* p = new child();
        sp.reset(p);
    }

    std::cout << "5)\n";
    {
        shared_ptr<parent> sp ( new child() );
        parent* p = new parent();
        sp.reset(p);
    }

    return 0;
}

