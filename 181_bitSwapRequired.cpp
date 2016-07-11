/*
181 将整数A转换为B

如果要将整数A转换为B，需要改变多少个bit位？

样例
如把31转换为14，需要改变2个bit位。

(31)10=(11111)2

(14)10=(01110)2
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        return count1Bits(a ^ b);
    }
    
    int count1Bits(int n)
    {
        int count = 0;
        while(n)
        {
            ++count;
            n = n & (n-1);
        }//while
        
        return count;
    }
};