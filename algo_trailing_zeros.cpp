#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (long long i=5; i<=n; i*=5) {
            res += (n / i);
        }

        return res;
    }
};

int main()
{
    Solution s;

    //cout << s.trailingZeroes(30) << "\n";
    cout << s.trailingZeroes(2147483647) << "\n";
}
