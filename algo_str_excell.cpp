#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (const auto& c: s)
        {
            res *= 26;
            res += c - 'A' + 1;
        }

        return res;
    }
};

int main()
{
    Solution s;
    string str {"ABCS"};

    std::cout << s.titleToNumber(str) << "\n";

    return 0;
}
