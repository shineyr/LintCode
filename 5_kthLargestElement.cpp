/*
5  第k大元素
题目
在数组中找到第k大的元素
样例
给出数组 [9,3,2,4,8]，第三大的元素是 4

给出数组 [1,2,3,4,5]，第一大的元素是 5，第二大的元素是 4，第三大的元素是 3，以此类推

挑战
要求时间复杂度为O(n)，空间复杂度为O(1)
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if(nums.empty() || k <= 0)
        {
            return -1;
        }//if
        
        int len = nums.size();
        int low = 0 , high = len - 1;
        int idx = partition(nums, low , high);
        //选好比较的索引大小
        while(idx != (len - k))
        {
            if(idx < (len - k))
            {
                low = idx + 1;
            }else
            {
                high = idx -1 ;
            }
            
            idx = partition(nums , low , high);
        }//while
        
        return nums[idx];
    }
    
    int partition(vector<int> &nums , int low , int high)
    {
        if(nums.empty())
        {
            return -1;
        }//if
        
        int i = low - 1;
        int x = nums[high];
        for(int j=low; j<high; ++j)
        {
            if(nums[j] < x)
            {
                ++i;
                exchange(nums[i] , nums[j]);
            }//if
        }//for
        
        exchange(nums[i+1] , nums[high]);
        return i+1;
    }
    
    void exchange(int &a , int &b)
    {
        //注意异或交换的陷阱
        if(a == b)
        {
            return;
        }
        a ^= b;
        b ^= a;
        a ^= b;
    }
};