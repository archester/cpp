#include <iostream>


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res = 0;
        bool inWord = false;
        while (*s != '\0') {
            if (*s == ' ') {
                inWord = false;
            }
            else if (inWord) {
                res++;
            }
            else {
                inWord = true;
                res = 1;
            }
            s++;
        }
        return res;
    }
};

int main()
{
    Solution s;

    std::cout << s.lengthOfLastWord("hello world") << "\n";
    std::cout << s.lengthOfLastWord(" ") << "\n";
    std::cout << s.lengthOfLastWord("") << "\n";
    std::cout << s.lengthOfLastWord("a a   bbb aaa ") << "\n";

    return 0;
}
