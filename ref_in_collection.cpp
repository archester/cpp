#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <list>


int main()
{
    srand(time(NULL));

    std::list<int> l = {1,2,3,4};
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
    std::random_shuffle(v.begin(), v.end());
    for(int i: l) {std::cout << i << " ";}  std::cout << "\n";
    for(int i: v) {std::cout << i << " ";}  std::cout << "\n";

    for(int& i: l) {i*=2;}
    for(int i: l) {std::cout << i << " ";}  std::cout << "\n";
    for(int i: v) {std::cout << i << " ";}  std::cout << "\n";

    return 0;
}

