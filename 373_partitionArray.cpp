/*
373 奇偶分割数组

分割一个整数数组，使得奇数在前偶数在后。

样例
给定 [1, 2, 3, 4]，返回 [1, 3, 2, 4]。
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if(nums.empty())
        {
            return ;
        }//if
        
        int len = nums.size();
        for(int l=0,r=len-1; l<r; )
        {
            while(nums[l] % 2 != 0)
            {
                ++l;
            }//if
            while(nums[r] % 2 == 0)
            {
                --r;
            }//if
            
            if(l < r)
            {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
            }//if
        }//for
    }
};