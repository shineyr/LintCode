/*
 41 最大子数组

给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。

 注意事项

子数组最少包含一个数

样例
给出数组[?2,2,?3,4,?1,2,1,?5,3]，符合要求的子数组为[4,?1,2,1]，其最大和为6

挑战
要求时间复杂度为O(n)
*/
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty())
        {
            return 0;
        }//if
        
        int len = nums.size();
        int maxSum = nums[0] , tmpSum = nums[0];
        for(int i=1;i<len;++i)
        {
            if(tmpSum < 0)
            {
                tmpSum = nums[i];
                continue;
            }else{
                if(tmpSum > maxSum)
                {
                    maxSum = tmpSum;
                }//if
                tmpSum += nums[i];
            }
        }//for
        if(tmpSum > maxSum)
        {
            maxSum = tmpSum;
        }//if
        return maxSum;
    }
};
