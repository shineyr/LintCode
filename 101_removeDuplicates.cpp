/*
101 删除排序数组中的重复数字 II

跟进“删除重复数字”：

如果可以允许出现两次重复将如何处理？



您在真实的面试中是否遇到过这个题？ Yes
样例
给出数组A =[1,1,1,2,2,3]，你的函数应该返回长度5，此时A=[1,1,2,2,3]。

*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.empty())
        {
            return 0;
        }//if
        
        int n = nums.size(), k=0, times=1;
        for(int i=1; i<n; ++i)
        {
            if(nums[i] != nums[k])
            {
                nums[++k] = nums[i];
                times = 1;
            }else if(nums[i] == nums[k]){
                if(times >= 2)
                {
                    continue;
                }else{
                    nums[++k] = nums[i];
                    ++times;
                }//else
            }//elif
        }//for
        
        nums.resize(k+1);
        return k+1;
    }
};