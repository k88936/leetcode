/**
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 determine if the input string is valid. 

 An input string is valid if: 

 
 Open brackets must be closed by the same type of brackets. 
 Open brackets must be closed in the correct order. 
 Every close bracket has a corresponding open bracket of the same type. 
 

 
 Example 1: 

 
 Input: s = "()" 
 

 Output: true 

 Example 2: 

 
 Input: s = "()[]{}" 
 

 Output: true 

 Example 3: 

 
 Input: s = "(]" 
 

 Output: false 

 Example 4: 

 
 Input: s = "([])" 
 

 Output: true 

 
 Constraints: 

 
 1 <= s.length <= 10⁴ 
 s consists of parentheses only '()[]{}'. 
 

 Related Topics 栈 字符串 👍 4611 👎 0

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
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                char top = st.top();
                if (c == ')' && top != '(')
                {
                    return false;
                }
                if (c == ']' && top != '[')
                {
                    return false;
                }
                if (c == '}' && top != '{')
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
