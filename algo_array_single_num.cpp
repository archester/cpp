#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (s.find(A[i]) != s.end()) {
                s.erase(A[i]);
            }
            else {
                s.insert(A[i]);
            }
        }

        return *(s.begin());
    }

    int singleNumber2(int A[], int n) {
        if (n==0) return 0;
        int res = A[0];
        for (int i=1; i<n; ++i) {
            res ^= A[i];
        }

        return res;
    }
};



int main()
{
    Solution s;
    int A[] = {12341111,12341111,99999,321324,321324};

    cout << s.singleNumber2(A, sizeof(A)/sizeof(A[0])) << "\n";
}
