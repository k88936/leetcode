/**
Given an array nums of n integers, return an array of all the unique 
quadruplets [nums[a], nums[b], nums[c], nums[d]] such that: 

 
 0 <= a, b, c, d < n 
 a, b, c, and d are distinct. 
 nums[a] + nums[b] + nums[c] + nums[d] == target 
 

 You may return the answer in any order. 

 
 Example 1: 

 
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 

 Example 2: 

 
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

 
 Constraints: 

 
 1 <= nums.length <= 200 
 -10⁹ <= nums[i] <= 10⁹ 
 -10⁹ <= target <= 10⁹ 
 

 Related Topics 数组 双指针 排序 👍 2004 👎 0

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
    vector<vector<int>> fourSum(vector<int>& nums, const int target)
    {
        // int n = nums.size();
        // vector<vector<int>> result;
        // if (n < 4)
        // {
        //     return result;
        // }
        // sort(nums.begin(), nums.end());
        // vector<int> diff(n);
        // diff[0] = nums[0];
        // for (int i = 1; i < n; i++)
        // {
        //     diff[i] = nums[i] - nums[i - 1];
        // }
        // int a, b, c, d;
        // for (a = 0; a < n - 3; a++)
        // {
        //     eval(a);
        //     c = n - 2;
        //     d = n - 1;
        //     for (b = a + 1; b < n - 2; b++)
        //     {
        //         eval(b);
        //         while (d > b + 1&&c>b)
        //         {
        //             if (diff[c] == 0 && c > b + 1)
        //             {
        //                 while (c > b + 1 && diff[c] == 0)
        //                 {
        //                     c--;
        //                     eval(c);
        //                 }
        //             }
        //             if (diff[d] == 0 && d > c + 1)
        //             {
        //                 while (d > c + 1 && diff[d] == 0)
        //                 {
        //                     d--;
        //                     eval(d);
        //                 }
        //             }
        //             const int sum = nums[a] + nums[b] + nums[c] + nums[d];
        //             if (sum == target)
        //             {
        //                 result.push_back({nums[a], nums[b], nums[c], nums[d]});
        //                 log("found at:"+to_string(a)+","+to_string(b)+","+to_string(c)+","+to_string(d));
        //                 break;
        //             }
        //             if (sum < target)
        //             {
        //                 while (diff[c] == 0 && c < n - 2)
        //                 {
        //                     c++;
        //                 }
        //                 while (diff[d] == 0 && d < n - 1)
        //                 {
        //                     d++;
        //                 }
        //                 c++;
        //                 d++;
        //                 eval(c);
        //                 eval(d);
        //                 break;
        //             }
        //             if (sum > target)
        //             {
        //                 if ((diff[d] == 0 || diff[c] < diff[d]) && diff[c] > 0)
        //                 {
        //                     c--;
        //                     eval(c);
        //                 }
        //                 if ((diff[c] == 0 || diff[d] <= diff[c]) && diff[d] > 0)
        //                 {
        //                     if (d > c + 1)
        //                     {
        //                         d--;
        //                         eval(d);
        //                     }
        //                     else
        //                     {
        //                         c--;
        //                         eval(c);
        //                     }
        //                 }
        //             }
        //         }
        //         while (nums[b] == nums[b + 1] && b < n - 2)
        //         {
        //             b++;
        //             eval(b);
        //         }
        //     }
        //     while (nums[a] == nums[a + 1] && a < b - 1)
        //     {
        //         a++;
        //         eval(a);
        //     }
        // }
        // return result;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    // vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    // vector<int> nums = {0, 0, 0, 0};
    vector<int> nums = {-3, -1, 0, 2, 4, 5};//0 1 2 6
    s.fourSum(nums, 1);
}
