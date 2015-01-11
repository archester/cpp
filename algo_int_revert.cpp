#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool minus = x < 0;
        if (minus) x = -x;
        int res = 0, prev_res = 0;
        while (x) {
            prev_res = res;
            res *= 10;
            res += x%10;

            if ((res-x%10)/10 != prev_res) {
                /*homegrown overflow detection*/
                return 0;
            }

            x = x/10;
        }

        return minus ? -1*res : res;
    }
};

int main()
{
    Solution s;

    cout << s.reverse(153423646) << "\n";
}
