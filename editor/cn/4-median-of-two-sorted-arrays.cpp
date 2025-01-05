/**
Given two sorted arrays nums1 and nums2 of size m and n respectively, return 
the median of the two sorted arrays. 

 The overall run time complexity should be O(log (m+n)). 

 
 Example 1: 

 
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
 

 Example 2: 

 
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

 
 Constraints: 

 
 nums1.length == m 
 nums2.length == n 
 0 <= m <= 1000 
 0 <= n <= 1000 
 1 <= m + n <= 2000 
 -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
 

 Related Topics 数组 二分查找 分治 👍 7343 👎 0

*/

#include "includes.h"

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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        auto h1 = nums1.begin(), h2 = nums2.begin();
        int total = (nums1.size() + nums2.size());
        int count = 0;
        if (total % 2 != 0)
            while (true)
            {
                int a = h1 == nums1.end() ? INT_MAX : *h1;
                int b = h2 == nums2.end() ? INT_MAX : *h2;

                if (a < b)
                {
                    h1++;
                    if (count == total / 2)
                    {
                        return a;
                    }
                }
                else
                {
                    h2++;
                    if (count == total / 2)
                    {
                        return b;
                    }
                }
                count++;
            }
        int before_mid = 0;
        while (true)
        {
            int a = h1 == nums1.end() ? INT_MAX : *h1;
            int b = h2 == nums2.end() ? INT_MAX : *h2;

            if (a < b)
            {
                ++h1;
                if (count == total / 2 - 1)
                {
                    before_mid = a;
                }
                else if (count == total / 2)
                {
                    return (before_mid + a) / 2.0;
                }
            }
            else
            {
                ++h2;
                if (count == total / 2 - 1)
                {
                    before_mid = b;
                }
                else if (count == total / 2)
                {
                    return (before_mid + b) / 2.0;
                }
            }
            count++;
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}
