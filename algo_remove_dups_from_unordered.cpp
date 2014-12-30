#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <array>
#include <list>

template <typename T>
void remove_dups(std::list<T>& list)
{
    std::unordered_set<T> seen;

    for (auto cur = list.begin(); cur != list.end(); )
    {
        if (seen.find(*cur) != seen.end())
        {
            list.erase(cur++);
        }
        else
        {
            seen.insert(*(cur++));
        }
    }
}

int main()
{
    std::list<int> l = {1,1,1,1,2,3,4,2,3,4,5,6,7,2,1,2,4};
    remove_dups(l);
    for (int i: l) {
        std::cout << i << ",";
    }
    std::cout << "\n";

    return 0;
}

