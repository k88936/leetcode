/**
Given an input string s and a pattern p, implement regular expression matching 
with support for '.' and '*' where: 

 
 '.' Matches any single character. 
 '*' Matches zero or more of the preceding element. 
 

 The matching should cover the entire input string (not partial). 

 
 Example 1: 

 
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
 

 Example 2: 

 
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, 
by repeating 'a' once, it becomes "aa".
 

 Example 3: 

 
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

 
 Constraints: 

 
 1 <= s.length <= 20 
 1 <= p.length <= 20 
 s contains only lowercase English letters. 
 p contains only lowercase English letters, '.', and '*'. 
 It is guaranteed for each appearance of the character '*', there will be a 
previous valid character to match. 
 

 Related Topics 递归 字符串 动态规划 👍 4009 👎 0

*/

#include <utility>

#include "includes.h"

#define LOCAL

//leetcode submit region begin(Prohibit modification and deletion)
#ifdef LOCAL
#define eval(x) {auto temp =x; cout << #x << " = " << temp << endl;}
#define test(x,y) if (x!=y) {auto temp=y; cout << "test failed: " << #x <<" expected:" <<temp<<" got:"<<x<<endl;}
#define log(x) cout <<x<<endl
#else
#define eval(x)
#define test(x,y)
#define log(x)
#endif

class state
{
public:
    virtual ~state() = default;
    state* next = nullptr;
    virtual bool match(string& target, int index);;
};

class match_word : public state
{
public:
    string word;
    bool match(string& target, int index) override;
};

bool state::match(string& target, int index)
{
    return next->match(target, index);
}

bool match_word::match(string& target, int index)
{
    if (index + word.size() > target.size())
    {
        return false;
    }
    for (int i = 0; i < word.size(); i++)
    {
        if (target[index + i] != word[i])
        {
            return false;
        }
    }
    index += word.size();
    if (next != nullptr)
    {
        return next->match(target, index);
    }
    return index == target.size();
}

class match_any_one : public state
{
public:
    bool match(string& target, int index) override;
};

bool match_any_one::match(string& target, int index)
{
    if (index >= target.size())
    {
        return false;
    }
    index++;
    if (next != nullptr)
    {
        return next->match(target, index);
    }
    return index == target.size();
}

class match_any_zero_or_more : public state
{
public:
    bool match(string& target, int index) override;
};

class match_char_zero_or_more : public state
{
public:
    char c;
    bool match(string& target, int index) override;
};


bool match_any_zero_or_more::match(string& target, int index)
{
    if (next == nullptr)
    {
        return true;
    }
    while (true)
    {
        if (next->match(target, index))
        {
            return true;
        }
        if (index >= target.size())
        {
            return false;
        }
        index++;
    }
}

bool match_char_zero_or_more::match(string& target, int index)
{
    while (true)
    {
        if (index >= target.size())
        {
            if (next)return next->match(target, index);
            return true;
        }
        if (next && next->match(target, index))
        {
            return true;
        }
        if (target[index] != c)
        {
            if (!next)
            {
                return false;
            }
            return next->match(target, index);
        }

        index++;
    }
}

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        auto* head = new state();
        state* cur = head;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == '.')
            {
                if (p[i + 1] == '*')
                {
                    match_any_zero_or_more* m = new match_any_zero_or_more();
                    log("add rule :match_any_zero_or_more");
                    cur->next = m;
                    cur = m;
                    i++;
                }
                else
                {
                    match_any_one* m = new match_any_one();
                    log("add rule :match_any_one");
                    cur->next = m;
                    cur = m;
                }
            }
            else
            {
                if (p[i + 1] == '*')
                {
                    match_char_zero_or_more* m = new match_char_zero_or_more();
                    m->c = p[i];
                    log("add rule :match_char_zero_or_more by: "+string(1,p[i]));
                    cur->next = m;
                    cur = m;
                    i++;
                }
                else
                {
                    match_word* m = new match_word();
                    int len = 0;
                    while (true)
                    {
                        len++;
                        if (i + len < p.length())
                        {
                            if (p[i + len] == '.')
                                break;
                            if (p[i + len] == '*')
                            {
                                len--;
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    m->word = p.substr(i, len);
                    log("add rule :match_word by: "+m->word);
                    cur->next = m;
                    cur = m;
                    i += len - 1;
                }
            }
        }

        return head->match(s, 0);
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    // eval(s.isMatch("mississippi", "mis*is*ip*."));
    // eval(s.isMatch("aaa", "a*a"));
    eval(s.isMatch("a", "a*c*"));
}
