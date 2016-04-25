/*
56 两数之和

给一个整数数组，找到两个数使得他们的和等于一个给定的数target。

你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。
注意这里下标的范围是1到n，不是以0开头。
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        if(nums.empty())
        {
            return vector<int>();
        }//if
        
        int len = nums.size();
        vector<int> ret;
        for(int i=0; i<len; ++i)
        {
            for(int j=i+1; j<len; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    return ret;
                }//if
            }//for
        }//for
        
        return vector<int>();
    }
};
