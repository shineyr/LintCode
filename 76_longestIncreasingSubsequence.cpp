/*
76  最长上升子序列

给定一个整数序列，找到最长上升子序列（LIS），返回LIS的长度。

最长上升子序列的定义：

最长上升子序列问题是在一个无序的给定序列中找到一个尽可能长的由低到高排列的子序列，这种子序列不一定是连续的或者唯一的。
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
样例

给出 [5,4,1,2,3]，LIS 是 [1,2,3]，返回 3
给出 [4,2,4,5,3,7]，LIS 是 [4,4,5,7]，返回 4
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
     
    //动态规划
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(nums.empty())
        {
            return 0;
        }//if
        
        vector<int> dp = getDp1(nums);
        int maxLen = 0, len = dp.size();
        for(int i=0; i<len; ++i)
        {
            if(dp[i] > maxLen)
            {
                maxLen = dp[i];
            }//if
        }//for
        
        return maxLen;
    }
    
    //O(n^2)的复杂度
    vector<int> getDp1(vector<int> &nums)
    {
        if(nums.empty())
        {
            return vector<int>();
        }//if
        
        int len = nums.size();
        vector<int> dp(len, 0);
        for(int i=0; i<len; ++i)
        {
            dp[i] = 1;
            for(int j=0; j<i; ++j)
            {
                if(nums[i] >= nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }//if
            }//for
        }//for
        
        return dp;
    }
};
