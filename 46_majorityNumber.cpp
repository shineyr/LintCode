/*
 46 主元素

给定一个整型数组，找出主元素，它在数组中的出现次数严格大于数组元素个数的二分之一。

样例
给出数组[1,1,1,1,2,2,2]，返回 1

挑战
要求时间复杂度为O(n)，空间复杂度为O(1)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if(nums.empty())
        {
            return -1;
        }//if
        
        int len = nums.size();
        int ret = nums[0],times = 1;
        for(int i=1;i<len;++i)
        {
            if(times == 0)
            {
                ret = nums[i];
                times = 0;
            }//if
            else if(nums[i] == ret)
            {
                ++times;
            }//elif
            else{
                --times;
            }//else
        }//for
        return ret;
    }
};
