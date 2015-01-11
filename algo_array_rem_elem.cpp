#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int removed = 0;
        for (int i = 0; i < n-removed; i++)
        {
            if (A[i] == elem)
            {
                A[i] = A[n-1-removed];
                removed++;
                i--;
            }
        }

        return n-removed;
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


    int A[] {3,3,3,3,1,2,3};
    int len = s.removeElement(A, sizeof(A)/sizeof(A[0]), 3);

    std::cout << "len=" << len << "\n";
    printArray(A, len);

}
