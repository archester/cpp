#include <iostream>
#include <string>
#include <stack>
#include <set>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        std::stack<char> tokens;

        for (auto c: s)
        {
            if (isOpeningToken(c))
            {
                tokens.push(c);
            }
            else if (isClosingToken(c))
            {
                if (tokens.empty()) return false;

                char opening = tokens.top();

                if (openingToken(c) != opening) return false;

                tokens.pop();
            }
        }

        return tokens.empty();
    }
private:
    char openingToken(char c) const
    {
        switch(c)
        {
        case '}': return '{';
        case ')': return '(';
        case ']': return '[';
        }

        return ' ';
    }

    bool isOpeningToken(char c) const
    {
        return (openingTokens.find(c) != openingTokens.end());
    }

    bool isClosingToken(char c) const
    {
        return (closingTokens.find(c) != closingTokens.end());
    }

    static const std::set<char> openingTokens;
    static const std::set<char> closingTokens;
};

const std::set<char> Solution::openingTokens =  {'{', '(', '['};
const std::set<char> Solution::closingTokens =  {'}', ')', ']'};

int main()
{
    Solution s;

    string str {"(f)f{f}(())["};


    cout << s.isValid(str) << "\n";
}

/*
 *
 * class Parser
{
private:
    static const std::set<char> openingTokens;
    static const std::set<char> closingTokens;

    char openingToken(char c) const;
public:
    bool isOpeningToken(char c) const;
    bool isClosingToken(char c) const;

    bool stringValid(std::string& s);
};

const std::set<char> Parser::openingTokens =  {'{', '(', '['};
const std::set<char> Parser::closingTokens =  {'}', ')', ']'};

bool Parser::isOpeningToken(char c) const
{
    return (openingTokens.find(c) != openingTokens.end());
}

bool Parser::isClosingToken(char c) const
{
    return (closingTokens.find(c) != closingTokens.end());
}

char Parser::openingToken(char c) const
{
    switch(c)
    {
    case '}': return '{';
    case ')': return '(';
    case ']': return '[';
    }

    assert(false);
}

bool Parser::stringValid(std::string& s)
{
    std::stack<char> tokens;

    for (auto c: s)
    {
        if (isOpeningToken(c))
        {
            tokens.push(c);
        }
        else if (isClosingToken(c))
        {
            if (tokens.empty()) return false;

            char opening = tokens.top();

            if (openingToken(c) != opening) return false;

            tokens.pop();
        }
    }

    return tokens.empty();
}

int main()
{
    Parser parser;
    std::vector<std:: string> strings = {"(f)f{f}(())", "(){dd}", "({())"};

    for (auto s: strings)
    {
        std::cout << s << " : " << parser.stringValid(s) << "\n";
    }

    return 0;
}
 * */
