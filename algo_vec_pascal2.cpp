#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& vec)
{
    for (auto i: vec) {
        cout << i << " ";
    }
    cout << "\n";
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> res;

        for (int i = 1; i<=rowIndex; ++i) {
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

        return std::move(res[rowIndex-1]);
    }
};



int main()
{
    Solution s;


    printVector( s.getRow(12)) ;
}
