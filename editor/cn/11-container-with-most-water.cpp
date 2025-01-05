/**
You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the iᵗʰ line are (i, 0) and (i, height[i]). 

 Find two lines that together with the x-axis form a container, such that the 
container contains the most water. 

 Return the maximum amount of water a container can store. 

 Notice that you may not slant the container. 

 
 Example 1: 
 
 
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,
7]. In this case, the max area of water (blue section) the container can 
contain is 49.
 

 Example 2: 

 
Input: height = [1,1]
Output: 1
 

 
 Constraints: 

 
 n == height.length 
 2 <= n <= 10⁵ 
 0 <= height[i] <= 10⁴ 
 

 Related Topics 贪心 数组 双指针 👍 5236 👎 0

*/

#include "includes.h"

#define LOCAL

//leetcode submit region begin(Prohibit modification and deletion)
#ifdef LOCAL
#define eval(x) cout << #x << " = " << x << endl
#define test(x,y) if (x!=y) { cout << "test failed: " << #x <<" expected:" <<y<<" got:"<<x<<endl;}
#define log(x) cout <<x<<endl
#else
#define eval(x)
#define test(x,y)
#define log(x)
#endif

class MaxHeap
{
public:
    void push(int val)
    {
        heap.push(val);
        count[val]++;
    }

    void pop()
    {
        if (!heap.empty())
        {
            int top = heap.top();
            heap.pop();
            count[top]--;
            if (count[top] == 0)
            {
                count.erase(top);
            }
        }
    }

    int top()
    {
        while (!heap.empty() && count[heap.top()] == 0)
        {
            heap.pop();
        }
        return heap.empty() ? -1 : heap.top();
    }

    void remove(int val)
    {
        if (count.find(val) != count.end())
        {
            count[val]--;
            if (count[val] == 0)
            {
                count.erase(val);
            }
        }
    }

    bool empty()
    {
        return heap.empty();
    }

private:
    std::priority_queue<int> heap;
    std::unordered_map<int, int> count;
};

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        // MaxHeap left, right;
        // for (int h : height)
        // {
        //     right.push(h);
        // }
        // right.push(0);
        // int max_area = 0;
        // for (int h : height)
        // {
        //     left.push(h);
        //     right.remove(h);
        //     int left_max = left.top();
        //     int right_max = right.top();
        //     max_area += min(left_max, right_max);
        // }
        // return max_area;

        int max_area = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};eval(s.maxArea(heights1));
    // vector<int> heights2 = {1, 1};    eval(s.maxArea(heights2));
}
