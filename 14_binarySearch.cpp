/*
14  二分查找
给定一个排序的整数数组（升序）和一个要查找的整数target，
用O(logn)的时间查找到target第一次出现的下标（从0开始），
如果target不存在于数组中，返回-1。

样例
在数组 [1, 2, 3, 3, 4, 5, 10] 中二分查找3，返回2。
*/
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.empty())
        {
            return -1;
        }//if
        
        int len = array.size();
        int lhs = 0, rhs = len-1;
        while(lhs <= rhs)
        {
            int mid = (lhs + rhs) / 2;
            if(array[mid] == target)
            {
                if(mid == 0)
                {
                    return mid;
                }//if
                else if(mid > 0 && array[mid-1] != target)
                {
                    return mid;
                }else{
                    rhs = mid - 1;
                }//else
            }else if(array[mid] > target)
            {
                rhs = mid - 1;
            }//elif
            else{
                lhs = mid + 1;
            }
        }//while
        return -1;
    }
};