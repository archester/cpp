#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int,int> hash;
        for (auto i: num)
        {
            if (hash.find(i) != hash.end())
            {
                hash[i] = hash[i] + 1;
            }
            else
            {
                hash[i] = 1;
            }
        }

        for (auto& i: hash)
        {
            if (i.second > num.size()/2)
                return i.first;
        }

        /*error scenario*/
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,1,1,2,2,1,3};
    vector<int> v2{2};
    vector<int> v3{1,2};

    std::cout << s.majorityElement(v) << "\n";
    std::cout << s.majorityElement(v2) << "\n";
    std::cout << s.majorityElement(v3) << "\n";
}
