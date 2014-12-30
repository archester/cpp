#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>

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
    srand(time(0));
    std::vector<Obj> vo;
    std::cout << "capacity: " << vo.capacity() << "\n";;
    vo.reserve(3);
    std::cout << "capacity: " << vo.capacity() << "\n";;
    vo.resize(3);
    std::cout << "capacity: " << vo.capacity() << "\n";;

    std::vector<std::shared_ptr<Obj>> lo = {std::make_shared<Obj>(3)
                                           ,std::make_shared<Obj>(4)};

    std::random_shuffle(lo.begin(),lo.end());
    for (std::shared_ptr<Obj> o: lo) {std::cout << "hello it is: " << o.get()->_tag << "\n";}

    Obj* p = new Obj();
    {
        std::unique_ptr<Obj> uo(p);
        f(uo);
    }
    std::cout << "was 6 destructed already?\n"; // was

    auto s = std::make_shared<Obj>();
    s->_tag;


    return 0;
}

