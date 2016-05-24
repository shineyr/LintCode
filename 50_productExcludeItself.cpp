/*
60 数组剔除元素后的乘积

给定一个整数数组A。

定义B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]， 计算B的时候请不要使用除法。

样例
给出A=[1, 2, 3]，返回 B为[6, 3, 2]
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
     
     //前缀后缀的思想
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<long long> A(n,0), B(n,0);
        B[n-1] = 1;
        for(int i=n-2; i>=0; --i)
        {
            B[i] = B[i+1] * nums[i+1];
        }//for
        
        A[0] = 1;
        for(int i=1; i<n; ++i)
        {
            A[i] = A[i-1] * nums[i-1];
        }//for
        
        for(int i=0; i<n; ++i)
        {
            B[i] *= A[i];
        }//for
        
        return B;
    }
};