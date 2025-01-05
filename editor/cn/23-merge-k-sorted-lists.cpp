/**
You are given an array of k linked-lists lists, each linked-list is sorted in 
ascending order. 

 Merge all the linked-lists into one sorted linked-list and return it. 

 
 Example 1: 

 
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
 

 Example 2: 

 
Input: lists = []
Output: []
 

 Example 3: 

 
Input: lists = [[]]
Output: []
 

 
 Constraints: 

 
 k == lists.length 
 0 <= k <= 10⁴ 
 0 <= lists[i].length <= 500 
 -10⁴ <= lists[i][j] <= 10⁴ 
 lists[i] is sorted in ascending order. 
 The sum of lists[i].length will not exceed 10⁴. 
 

 Related Topics 链表 分治 堆（优先队列） 归并排序 👍 2935 👎 0

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        auto l1 = list1;
        auto l2 = list2;
        auto dummy = new ListNode();
        auto current = dummy;
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
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> q(
        //     [](ListNode* a, ListNode* b) { return a->val > b->val; });
        // for (auto list : lists)
        // {
        //     if (list)
        //     {
        //         q.push(list);
        //     }
        // }
        // auto dummy = new ListNode();
        // ListNode* cur = dummy;
        // while (true)
        // {
        //     if (q.empty())
        //     {
        //         break;
        //     }
        //     auto top = q.top();
        //     q.pop();
        //     cur->next = top;
        //     cur = cur->next;
        //     if (top->next)
        //     {
        //         q.push(top->next);
        //     }
        // }
        // return dummy->next;
        if (lists.empty())
        {
            return nullptr;
        }
        int n = lists.size();
        while (n > 1)
        {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
}
