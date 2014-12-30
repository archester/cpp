#include <iostream>
#include <functional>
#include <string>

/*rotate string to the right by k-elements*/
bool rotate(std::string& s, size_t k)
{
    if (s.length() < k)
    {
        return false;
    }

    s = s.substr(s.length()-k, s.length()) + s.substr(0, s.length()-k);

    return true;
}

/*rotate string to the right by k-elements - NOT WORKING!*/
bool rotate_inplace(std::string& s, size_t k)
{
    if (s.length() == 0) return false;
    for (size_t i = 0, j=0 ; i < k; ++i)
    {
        size_t next_id = j+k % s.length();
        auto c = s[next_id];
        s[next_id] = s[j];
        j = next_id;
    }

    return true;
}

int main()
{
    std::string s = "abcdef";

    if (rotate_inplace(s,2))
    {
        std::cout << s << "\n";
    }

    return 0;
}

