/**
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. 

 Notice that the solution set must not contain duplicate triplets. 

 
 Example 1: 

 
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not 
matter.
 

 Example 2: 

 
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
 

 Example 3: 

 
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

 
 Constraints: 

 
 3 <= nums.length <= 3000 
 -10⁵ <= nums[i] <= 10⁵ 
 

 Related Topics 数组 双指针 排序 👍 7198 👎 0

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
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        ranges::sort(nums);
        int i, j, k;
        for (i = 0; i < n - 2; i++)
        {

            if (i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            eval(i);
            k = n - 1;
            for (j = i + 1; j < k; j++)
            {
                if (j>i+1&&nums[j]==nums[j-1])
                {
                    continue;
                }
                eval(j);
                while (nums[i] + nums[j] + nums[k] > 0 && k > j + 1)
                {
                    k--;
                    eval(k);
                }
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    log("push");
                    eval(i);
                    eval(j);
                    eval(k);
                    log("back");
                }
                eval(k);
            }
        }
        return result;
    }
};

class Solutioni
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first)
        {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second)
            {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target)
                {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target)
                {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};


//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    // vector<int> nums1 = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    vector<int> nums1 = {-3, -2, -1, 0, 0, 1, 2, 3};
    s.threeSum(nums1);

    // vector<int> nums2 = {0, 1, 1};
    // s.threeSum(nums2);
    // vector<int> nums3 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // s.threeSum(nums3);
}
