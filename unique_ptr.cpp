#include <iostream>
#include <thread>
#include <atomic>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

struct s
{
    ~s()
    {
        std::cout << "~s()\n";
    }
};

void f(unique_ptr<s>)
{

}

int main()
{
    std::cout << "1)\n";
    {
        unique_ptr<s> up (new s);
    }

    std::cout << "2)\n";
    {
        s* s_ = new s();
        unique_ptr<s> up (new s());
        up.reset(s_);
    }

    std::cout << "3)\n";
    {
        s* s_ = new s();
        unique_ptr<s> up;
        up.reset(s_);
    }

    std::cout << "4)\n";
    {
        unique_ptr<s> up (new s);
        unique_ptr<s> up2;
        // This causes double free coruption:
        //up2.reset(up.get());
    }

    std::cout << "5)\n";
    {
        unique_ptr<s> up (new s);
        // This does not work as unique_ptr does not have copy contructor
        //f(up);
    }

    // The way to solve 5)
    std::cout << "6)\n";
    {
        unique_ptr<s> up (new s);
        f(move(up));
    }

    // Can be freely used with stl containers
    std::cout << "7)\n";
    {
        std::vector<unique_ptr<s>> v;
        v.push_back(unique_ptr<s>(new s));
        v.push_back(unique_ptr<s>(new s));
        // This sorting makes no sense but works.
        sort(v.begin(), v.end());
    }

    return 0;
}

