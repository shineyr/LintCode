/*
81 中位数 II

数字是不断进入数组的，在每次添加一个新的数进入数组的同时返回当前新数组的中位数。

说明

中位数的定义：

    中位数是排序后数组的中间值，如果有数组中有n个数，则中位数为A[(n-1)/2]。
    比如：数组A=[1,2,3]的中位数是2，数组A=[1,19]的中位数是1。

样例

持续进入数组的数的列表为：[1, 2, 3, 4, 5]，则返回[1, 1, 2, 2, 3]

持续进入数组的数的列表为：[4, 5, 1, 3, 2, 6, 0]，则返回 [4, 4, 4, 3, 3, 3, 3]

持续进入数组的数的列表为：[2, 20, 100]，则返回[2, 2, 20]

*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    
    //方法一：数据流中位数，维护两个结构 
     vector<int> medianII(vector<int> &nums) {
        // write your code here
        multiset<int> left, right;
        vector<int> res;
        bool flag = true;
        for (int n : nums) {
            int tmp = n;
            if (flag) {
                if (!right.empty() && n > *right.begin()) {
                    right.insert(n);
                    tmp = *right.begin();
                    right.erase(right.find(tmp));
                }
                left.insert(tmp);
            } else {
                if (!left.empty() && n < *left.rbegin()) {
                    left.insert(n);
                    tmp = *left.rbegin();
                    left.erase(left.find(tmp));
                }
                right.insert(tmp);
            }
            flag = !flag;
            res.push_back(*left.rbegin());
        }
        return res;
    } 
    
    /*方法二：线性处理，但是会超时*/
    vector<int> medianII_2(vector<int> &nums) {
        // write your code here
        if(nums.empty())
        {
            return vector<int>();
        }//if
        
       int len = nums.size();
       vector<int> ret,v;
       v.push_back(nums[0]);
       ret.push_back(nums[0]);
       
       for(int i=1; i<len; ++i)
       {
           v.push_back(nums[i]);
           ret.push_back(median(v));
       }//for
       
       return ret;
    }
    
    
    int median(vector<int> &nums)
    {
        if(nums.empty())
        {
            return 0;
        }//if
        
        int lhs = 0 , rhs = nums.size()-1;
        int mid = (lhs + rhs) / 2;
        
        int idx = partition(nums, lhs , rhs);
        while(idx != mid && lhs <= rhs)
        {
            if(idx < mid)
            {
                lhs = idx + 1;
            }else{
                rhs = idx - 1;
            }//if
            
            idx = partition(nums, lhs , rhs);
        }//while
        
        return nums[idx];
    }
    
    int partition(vector<int> &nums, int left, int high)
    {
        if(nums.empty() || left > high)
        {
            return -1;
        }//if
        
        int low = left-1, pivot = nums[high];
        for(int i=left; i<high; ++i)
        {
            if(nums[i] <= pivot)
            {
                ++low;
                exchange(nums[low], nums[i]);
            }//if
        }//for
        
        exchange(nums[low+1], nums[high]);
        return low+1;
    }//partition
    
    void exchange(int &a, int &b)
    {
        if(a == b)
        {
            return ;
        }//if
        
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

