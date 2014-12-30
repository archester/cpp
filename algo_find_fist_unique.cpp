#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>

int main()
{
    std::array<int,10> ar = {1,1,2,3,2,1,3,5,4,1};
    std::unordered_map<int,size_t> count;


    for (int i: ar)
    {
        auto it = count.find(i);
        if (it != count.end())
        {
            it->second++;
        }
        else
        {
            count[i] = 1;
        }
    }

    for (int i: ar)
    {
        if (1 == count[i])
        {
            std::cout << "Found first unique: " << i << "\n";
            break;
        }
    }


    return 0;
}

