

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct s
{
    ~s()
    {
        std::cout << "~s()\n";
    }
};

int main()
{
    shared_ptr<s> ps3;
    weak_ptr<s> wp_g;

    std::cout << "1)\n";
    {
        auto ps = make_shared<s>();
        auto ps2 = ps;
        ps3 = ps2;
    }

    std::cout << "2)\n";
    {
        vector<shared_ptr<s>> vp = { make_shared<s>(), make_shared<s>() };
    }

    std::cout << "3)\n";
    {
        s* s_ = new s;
        shared_ptr<s> sp;
        sp.reset(s_);
        weak_ptr<s> wp(sp);
        wp_g = wp;
        wp_g.lock();
    }

    std::cout << "end)\n";

    return 0;
}

