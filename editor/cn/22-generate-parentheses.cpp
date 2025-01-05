/**
Given n pairs of parentheses, write a function to generate all combinations of 
well-formed parentheses. 

 
 Example 1: 
 Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
 
 Example 2: 
 Input: n = 1
Output: ["()"]
 
 
 Constraints: 

 
 1 <= n <= 8 
 

 Related Topics 字符串 动态规划 回溯 👍 3747 👎 0

*/

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
class Solution
{
public:
    vector<vector<string>> cache;

    vector<string> generateParenthesis(int n)
    {
        cache.resize(n + 1);
        cache[0] = {""};
        for (int i = 1; i < n + 1; ++i)
        {
            // unordered_set<string> s;
            set<string> s;
            for (int j = 0; j < i; ++j)
            {
                vector<string>& left = cache[j];
                vector<string>& right = cache[i - j];
                for (const string& l : left)
                {
                    for (const string& r : right)
                    {
                        s.insert(l + r);
                    }
                }
            }
            cache[i].assign(s.begin(), s.end());
            for (auto str : cache[i - 1])
            {
                cache[i].push_back("(" + str + ")");
            }
        }
        return cache[n];
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    s.generateParenthesis(3);
}
