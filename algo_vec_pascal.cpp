#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<vector<int>>& vec)
{
    for (const auto& v: vec) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

class Solution {
public:
    vector<vector<int> > generate(int numRows) {

        vector<vector<int>> res;

        for (int i = 1; i<=numRows; ++i) {
            vector<int> row(i);
            for (int j = 0; j < i; ++j)
            {
                if ((j==0) || (j==i-1))  {
                    row[j] = 1;
                }
                else {
                    row[j] = res[i-2][j-1] + res[i-2][j];
                }
            }
            res.push_back(row);
        }

        return std::move(res);
    }
};



int main()
{
    Solution s;


    printVector( s.generate(8)) ;
}
