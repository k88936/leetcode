/**
Write a function to find the longest common prefix string amongst an array of 
strings. 

 If there is no common prefix, return an empty string "". 

 
 Example 1: 

 
Input: strs = ["flower","flow","flight"]
Output: "fl"
 

 Example 2: 

 
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

 
 Constraints: 

 
 1 <= strs.length <= 200 
 0 <= strs[i].length <= 200 
 strs[i] consists of only lowercase English letters. 
 

 Related Topics 字典树 字符串 👍 3243 👎 0

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
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
