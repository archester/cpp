#include <iostream>
#include <functional>
#include <string>

int main()
{
    auto print = [](std::string s) {std::cout << s << "\n";};
    auto print_yes = std::bind(print, "yes");
    auto print_no = std::bind(print, "no");


    print_yes();
    print_no();

    return 0;
}

