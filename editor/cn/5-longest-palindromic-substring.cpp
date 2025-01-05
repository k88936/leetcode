/**
Given a string s, return the longest palindromic substring in s. 

 
 Example 1: 

 
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
 

 Example 2: 

 
Input: s = "cbbd"
Output: "bb"
 

 
 Constraints: 

 
 1 <= s.length <= 1000 
 s consist of only digits and English letters. 
 

 Related Topics 双指针 字符串 动态规划 👍 7473 👎 0

*/

#include "includes.h"

#define LOCAL

//leetcode submit region begin(Prohibit modification and deletion)
#ifdef LOCAL
#define debug(x,y) cout << x << ": "<<#y << " = " << y << endl
#else
#define debug(x,y)
#endif
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int i = 0, j = 0;
        int max_len = 1;

        int start = 0;
        while (i < n)
        {
            if (i + 1 < n && s.at(i) == s.at(i + 1))
            {
                debug("enter 2", i);

                j = 0;
                while (i - j >= 0 && i + 1 + j < n && s.at(i - j) == s.at(i + 1 + j))
                {
                    j++;
                }
                int len = 2 * j;
                if (len > max_len)
                {
                    max_len = len;
                    start = i - j + 1;
                }
            }
            if (i + 2 < n && s.at(i) == s.at(i + 2))
            {
                debug("enter 3", i);
                j = 0;
                while (i - j >= 0 && i + 2 + j < n && s.at(i - j) == s.at(i + 2 + j))
                {
                    j++;
                }
                int len = 2 * j + 1;
                if (len > max_len)
                {
                    max_len = len;
                    start = i - j + 1;
                }
            }

            i++;
        }
        return s.substr(start, max_len);
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;

    string str = "bb";
    // string str = "cbbd";
    cout << s.longestPalindrome(str) << endl;
}
