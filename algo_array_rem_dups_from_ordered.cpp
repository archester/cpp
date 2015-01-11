#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {

        if (n <= 0) return 0;

        int last_valid = 0;
        for (int i = 1;  i < n; i++)
        {
            while ((A[last_valid] == A[i]) && (i < n)) {
                i++;
            }
            if (i<n) {
                A[++last_valid] = A[i];
            }
        }

        return last_valid + 1;
    }
};

void printArray(int A[], int n) {
    for (int i=0; i<n; ++i) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int main()
{
    Solution s;


    int A[] {1,1,1,1,2,2,3,3};
    int len = s.removeDuplicates(A, sizeof(A)/sizeof(A[0]));

    std::cout << "len=" << len << "\n";
    printArray(A, len);

}
