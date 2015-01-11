#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    void reverseWords(string &s) {
        string res;

        if (s.length() == 0) return;

        auto len = s.length();
        auto beg = len-1;
        auto end = len-1;
        for (; beg > 0; --beg)
        {
            if (s[beg] == ' ')
            {
                while (end == ' ' && end > beg) end--;
                res = res + s.substr(beg, end - beg + 1) + " ";
                end = beg;
            }
        }

        while (end == ' ' && end >= beg) end--;
        if (end>beg)
            res = res + s.substr(beg, end - beg+1);


        if (res.length() > 0 && s[res.length()-1] == ' ')
        {
            res = res.substr(0, res.length()-1);
        }

        s = std::move(res);
    }
};

int main()
{
    Solution s;
    //string ss {"         abc            def            ghij      klmn                      opr    "};
    string ss {"   abc    def     "};
    s.reverseWords(ss);

    std::cout << ss << "$\n";

    return 0;
}
