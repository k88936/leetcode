/**
Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent. Return the answer in any order. 

 A mapping of digits to letters (just like on the telephone buttons) is given 
below. Note that 1 does not map to any letters. 
 
 
 Example 1: 

 
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 

 Example 2: 

 
Input: digits = ""
Output: []
 

 Example 3: 

 
Input: digits = "2"
Output: ["a","b","c"]
 

 
 Constraints: 

 
 0 <= digits.length <= 4 
 digits[i] is a digit in the range ['2', '9']. 
 

 Related Topics 哈希表 字符串 回溯 👍 2974 👎 0

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
    vector<string> letterCombinations(string digits)
    {
        map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> ans;

        for (char digit : digits)
        {
            int n = ans.size();
            if (n == 0)
            {
                for (char c : m[digit])
                {
                    ans.emplace_back(1, c);
                }
            }
            else
            {
                vector<string> temp;
                for (int i = 0; i < n; i++)
                {
                    for (char c : m[digit])
                    {
                        temp.push_back(ans[i] + c);
                    }
                }
                ans = move(temp);
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
