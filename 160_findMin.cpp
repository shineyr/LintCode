/*
160 寻找旋转排序数组中的最小值 II

假设一个旋转排序的数组其起始位置是未知的（比如0 1 2 4 5 6 7 可能变成是4 5 6 7 0 1 2）。

你需要找到其中最小的元素。

数组中可能存在重复的元素。

样例
给出[4,4,5,6,7,0,1,2]  返回 0
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if(num.empty())
        {
            return -1;
        }
        
        int len = num.size();
        int lhs = 0, rhs = len-1;
        while(num[lhs] >= num[rhs])
        {
            if(rhs - lhs == 1)
            {
                return num[rhs];
            }//if
            
            int mid = (lhs + rhs) / 2;
            
            if(num[lhs] == num[rhs] && num[lhs] == num[mid])
            {
                return midInorder(num, lhs, rhs);
            }
            if(num[mid] >= num[lhs])
            {
                lhs = mid;
            }else if(num[mid] <= num[rhs]){
                rhs = mid;
            }
        }
        return num[lhs];
    }
    
    int midInorder(vector<int> &num, int lhs, int rhs)
    {
        if(num.empty() || lhs <0 || rhs >= num.size())
        {
            return -1;
        }
        int ret = num[lhs];
        for(int i=lhs+1; i<=rhs; ++i)
        {
            if(ret > num[i])
            {
                ret = num[i];
            }
        }
        return ret;
    }
};