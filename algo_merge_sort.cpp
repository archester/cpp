#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <cassert>

typedef std::vector<int> vint;

vint merge_sort(vint& left, vint& right)
{
    if (left.size() > 1)
    {
        vint l(left.begin(), left.begin()+left.size()/2);
        vint r(left.begin()+left.size()/2, left.end());
        left = merge_sort(l,r);
    }

    if (right.size() > 1)
    {
        vint l(right.begin(), right.begin()+right.size()/2);
        vint r(right.begin()+right.size()/2, right.end());
        right = merge_sort(l,r);
    }

    vint result(left.size()+right.size());

    auto lint = left.begin();
    auto rint = right.begin();
    size_t pos = 0;
    while (lint != left.end() && rint != right.end())
    {
        if (*lint > *rint)
        {
            result[pos++] = *(rint++);
        }
        else
        {
            result[pos++] = *(lint++);
        }
    }

    while (lint != left.end())
    {
        result[pos++] = *(lint++);
    }

    while (rint != right.end())
    {
        result[pos++] = *(rint++);
    }

    return result;
}

vint merge_and_print(vint& v)
{
    vint vl(v.begin(), v.begin() + v.size()/2);
    vint vr(v.begin() + v.size()/2, v.end());
    vint res = merge_sort(vl, vr);

    for (auto i: res)
    {
        std::cout << i << ",";
    }
    std::cout << "\n";

    return res;
}

int main()
{
    vint res;
    {
        vint v = {1,3,4,5,24,3,5,2,534,2,4,2,423,2,1,2,31,2,4,5,24,25,3,-1,23};
        res = merge_and_print(v);
        assert(res[0] == *std::min(res.begin(), res.end()));
        assert(res[res.size()] == *std::max(res.begin(), res.end()));
    }

    {
        vint v = {};
        res = merge_and_print(v);
        assert(res.size() == 0);
    }


    return 0;
}

