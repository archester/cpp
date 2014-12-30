#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

using std::cout;
using std::string;


class Printer {
public:

    Printer() {}

    Printer(const Printer& other)
    {
        cout << "copying Printer\n";
    }

    Printer(const Printer&& other)
    {
        cout << "moving Printer\n";
    }

    void print(int i, int j)
    {
        cout << "i=" << i <<",j=" << j <<"\n";
    }

    void print0()
    {
        cout << "0\n";
    }
};

int main()
{
    using functionObj = std::function<void()>;
    std::vector< functionObj > functionObjects;
    functionObjects.reserve(10);

    {
        Printer p;
        std::string s = "string";

        auto sec = std::chrono::seconds(1);
        auto sleep = [=] () {std::this_thread::sleep_for(sec);};

        functionObjects.push_back( std::bind(&Printer::print, p, 1, 2) );
        functionObjects.push_back( sleep );
        functionObjects.push_back( std::bind(&Printer::print0, p) );
        functionObjects.push_back( sleep );
        functionObjects.push_back( [] {cout << "lambda\n"; return 1;} );
        functionObjects.push_back( sleep );
        functionObjects.push_back( [=] {cout << "lambda " + s + "\n"; return 1;} );
    }

    for (auto& f: functionObjects) {
        f();
    }

    return 0;
}

