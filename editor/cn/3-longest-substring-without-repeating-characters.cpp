/**
Given a string s, find the length of the longest substring without repeating 
characters. 


 Example 1: 

 
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
 

 Example 2: 

 
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
 

 Example 3: 

 
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a 
substring.
 

 
 Constraints: 

 
 0 <= s.length <= 5 * 10⁴ 
 s consists of English letters, digits, symbols and spaces. 
 

 Related Topics 哈希表 字符串 滑动窗口 👍 10511 👎 0

*/

#include "includes.h"

#define LOCAL

//leetcode submit region begin(Prohibit modification and deletion)
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        bool count[numeric_limits<char>::max()] = {false};
        int n = s.length();
        int i = 0, j = 0;
        int max = 0;

        for (i = 0; i < n; i++)
        {
            while (j < n && count[s[j]] == 0)
            {
                count[s[j]]=true;
                j++;
            }
            max = std::max(max, j - i);
            count[s[i]]=false;
        }
        return max;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
