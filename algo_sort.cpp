#include <array>
#include <iostream>

using namespace std;

using ArrayInt = array<int,10>;

void printArray(const ArrayInt& a) {
    for (const auto& i: a) {
        cout << i << " ";
    }
    cout << "\n";
}

void insertionSort(ArrayInt& a)
{
    for (size_t i=0; i<a.size(); ++i) {
        auto x = a[i];
        auto j = i-1;
        while (x<a[j] && j>=0) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void selectionSort(ArrayInt& a)
{
    for (auto pos=0; pos < a.size(); ++pos) {
        auto min_idx = pos;
        for (auto i = pos+1; i < a.size(); ++i) {
            if (a[min_idx] > a[i]) {
                min_idx = i;
            }
        }
        if (min_idx != pos) {
            swap(a[pos], a[min_idx]);
        }
    }
}

int main()
{
    {
        ArrayInt a{9,8,7,6,5,4,3,2,1,0};
        insertionSort(a);
        printArray(a);
    }
    {
        ArrayInt a{9,8,7,6,5,4,3,2,1,0};
        selectionSort(a);
        printArray(a);
    }
}
