/**
You are given the heads of two sorted linked lists list1 and list2. 

 Merge the two lists into one sorted list. The list should be made by splicing 
together the nodes of the first two lists. 

 Return the head of the merged linked list. 

 
 Example 1: 
 
 
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
 

 Example 2: 

 
Input: list1 = [], list2 = []
Output: []
 

 Example 3: 

 
Input: list1 = [], list2 = [0]
Output: [0]
 

 
 Constraints: 

 
 The number of nodes in both lists is in the range [0, 50]. 
 -100 <= Node.val <= 100 
 Both list1 and list2 are sorted in non-decreasing order. 
 

 Related Topics 递归 链表 👍 3661 👎 0

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        auto l1 = list1;
        auto l2 = list2;
        ListNode dummy;
        auto current = &dummy;
        while (true)
        {
            if (l1 == nullptr && l2 == nullptr)
            {
                break;
            }
            if (l1 == nullptr)
            {
                current->next = l2;
                break;
            }
            if (l2 == nullptr)
            {
                current->next = l1;
                break;
            }
            if (l1->val < l2->val)
            {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    auto res = s.mergeTwoLists(l1, l2);
}
