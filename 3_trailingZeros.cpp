/*
3 题目 设计一个算法，计算出n阶乘中尾部零的个数
样例
11! = 39916800，因此应该返回 2
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros1(long long n) {
        long long num = 0;
        for(long long i=5; i<=n ; i+=5)
        {
            long long j=i;
            while(j % 5 == 0)
            {
                ++num;
                j /= 5;
            }//while
        }//for
        return num;
    }
    
     long long trailingZeros(long long n) {
        long long num = 0;
        while(n)
        {
            num += n/5;
            n /= 5;
        }
        return num;
    }
};
