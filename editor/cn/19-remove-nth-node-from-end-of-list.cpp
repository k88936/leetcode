/**
Given the head of a linked list, remove the nᵗʰ node from the end of the list 
and return its head. 

 
 Example 1: 
 
 
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
 

 Example 2: 

 
Input: head = [1], n = 1
Output: []
 

 Example 3: 

 
Input: head = [1,2], n = 1
Output: [1]
 

 
 Constraints: 

 
 The number of nodes in the list is sz. 
 1 <= sz <= 30 
 0 <= Node.val <= 100 
 1 <= n <= sz 
 

 
 Follow up: Could you do this in one pass? 

 Related Topics 链表 双指针 👍 3006 👎 0

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int cnt = 0;
        vector<ListNode*> vals;
        while (head)
        {
            vals.push_back(head);
            cnt++;
            head = head->next;
        }
        if (cnt == n)
        {
            return vals[0]->next;
        }
        vals[cnt - n - 1]->next = vals[cnt - n]->next;
        delete vals[cnt - n];
        return vals[0];
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
