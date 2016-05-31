/*
100 删除排序数组中的重复数字

给定一个排序数组，在原数组中删除重复出现的数字，使得每个元素只出现一次，并且返回新的数组的长度。

不要使用额外的数组空间，必须在原地没有额外空间的条件下完成。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出数组A =[1,1,2]，你的函数应该返回长度2，此时A=[1,2]。
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
        
        int n = nums.size(),k=0;
        
        for(int i=1;i<n;++i)
        {
            if(nums[i] != nums[k])
            {
                nums[++k] = nums[i];
            }//if
        }//for
        nums.resize(k+1);
        return k+1;
    }
};