#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x <= 0 ) return 0;

        int res = static_cast<int>
                (sqrt(0, x, x));

        if ((res+1)*(res+1) == x) res++;

        return res;
    }
private:
    static constexpr auto epsilon = 0.1;

    double sqrt(double from, double to, double target) {
        double mid = (from + to) / 2;
        if (mid*mid > target) {
            return sqrt(from, mid, target);
        }
        else if (target-mid*mid <= epsilon) {
            return mid;
        }
        else {
            return sqrt(mid, to, target);
        }

    }
};

int main()
{
    Solution s;

    cout << s.sqrt(2147483647) << "\n";
    cout << s.sqrt(9) << "\n";
    cout << s.sqrt(10) << "\n";
}
