/**
Given a linked list, swap every two adjacent nodes and return its head. You 
must solve the problem without modifying the values in the list's nodes (i.e., only 
nodes themselves may be changed.) 

 
 Example 1: 

 
 Input: head = [1,2,3,4] 
 

 Output: [2,1,4,3] 

 Explanation: 

 

 Example 2: 

 
 Input: head = [] 
 

 Output: [] 

 Example 3: 

 
 Input: head = [1] 
 

 Output: [1] 

 Example 4: 

 
 Input: head = [1,2,3] 
 

 Output: [2,1,3] 

 
 Constraints: 

 
 The number of nodes in the list is in the range [0, 100]. 
 0 <= Node.val <= 100 
 

 Related Topics 递归 链表 👍 2334 👎 0

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
