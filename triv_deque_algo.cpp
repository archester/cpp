#include <cstdio>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cassert>
#include <deque>
#include <iterator>

using std::string;
using std::stringstream;
using std::set;
using std::cout;
using std::vector;
using std::deque;
using std::getline;

typedef unsigned int uint;
using std::string;
using std::equal;

int main()
{
    typedef deque<int> set_int;
    set_int si = {1,4,5,6,7,8};

    for (auto& i: si) { std::cout << i << " "; } std::cout << "\n";

    for (auto& i: si) {
        int& ii = const_cast<int&>(i);
        ii*=(2*(ii%2));
    }

    for (auto& i: si) { std::cout << i << " "; } std::cout << "\n";

    std::sort(si.begin(), si.end(), [](const int& a, const int& b) -> bool {return a<b;});

    std::copy(si.begin(), si.end(), std::ostream_iterator<int>(cout, " "));
    cout<<"\n";
}
