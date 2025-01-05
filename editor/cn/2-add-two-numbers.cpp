/**
You are given two non-empty linked lists representing two non-negative integers.
 The digits are stored in reverse order, and each of their nodes contains a 
single digit. Add the two numbers and return the sum as a linked list. 

 You may assume the two numbers do not contain any leading zero, except the 
number 0 itself. 

 
 Example 1: 
 
 
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
 

 Example 2: 

 
Input: l1 = [0], l2 = [0]
Output: [0]
 

 Example 3: 

 
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

 
 Constraints: 

 
 The number of nodes in each linked list is in the range [1, 100]. 
 0 <= Node.val <= 9 
 It is guaranteed that the list represents a number that does not have leading 
zeros. 
 

 Related Topics 递归 链表 数学 👍 10975 👎 0

*/

#include "includes.h"

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto head = new ListNode(0);
        auto cur = head;
        int next_val = 0;
        while (true)
        {
            cur->val += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            if (cur->val >= 10)
            {
                next_val = 1;
                cur->val -= 10;
            }
            else
            {
                next_val = 0;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;

            if (!l1 && !l2 && !next_val)
            {
                break;
            }
            cur->next = new ListNode(next_val);
            cur = cur->next;
        }
        return head;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
