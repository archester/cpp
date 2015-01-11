#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool done = false;
        for (auto it = digits.rbegin();
             (!done) && (it != digits.rend());
             ++it)
        {
            if (*it < 9) {
                *it = *it + 1;
                done = true;
            }
            else {
                *it = 0;
            }
        }
        if (!done) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

void printVector(const vector<int> &digits)
{
    for (auto i: digits) {
        cout << i;
    }
    cout << "\n";
}

int main()
{
    Solution s;
    vector<int> v{1,1,1,2,2,1,3};
    vector<int> v2{2};
    vector<int> v3{1,9};


    printVector( s.plusOne(v) ) ;
    printVector( s.plusOne(v2) ) ;
    printVector( s.plusOne(v3) ) ;
}
