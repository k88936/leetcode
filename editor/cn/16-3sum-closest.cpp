/**
Given an integer array nums of length n and an integer target, find three 
integers in nums such that the sum is closest to target. 

 Return the sum of the three integers. 

 You may assume that each input would have exactly one solution. 

 
 Example 1: 

 
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

 Example 2: 

 
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

 
 Constraints: 

 
 3 <= nums.length <= 500 
 -1000 <= nums[i] <= 1000 
 -10⁴ <= target <= 10⁴ 
 

 Related Topics 数组 双指针 排序 👍 1687 👎 0

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
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        int closest = 100000;
        ranges::sort(nums);
        int i, j, k;
        for (i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            k = n - 1;
            for (j = i + 1; j < k; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int sum_last=nums[i] + nums[j] + nums[k];
                while (k > j)
                {
                    const int sum = nums[i] + nums[j] + nums[k];
                    if (sum == target)
                    {
                        return target;
                    }
                    if (sum < target)
                    {
                        if (abs(sum - target) < abs(closest - target))
                        {
                            closest = sum;
                        }
                        break;
                    }
                    if (sum > target)
                    {
                        k--;
                    sum_last = sum;
                    }
                }
                if (abs(sum_last - target) < abs(closest - target))
                {
                    closest = sum_last;
                }
            }
        }
        return closest;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    // vector<int> nums1 = {-1, 2, 1, -4};
    vector<int> nums1 = {0,0,0};
  cout<<  s.threeSumClosest(nums1, 10000);
}
