/*
111 爬楼梯

假设你正在爬楼梯，需要n步你才能到达顶部。但每次你只能爬一步或者两步，你能有多少种不同的方法爬到楼顶部？

样例
比如n=3，1+1+1=1+2=2+1=3，共有3中不同的方法
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        vector<int> ways(n+1,0);
        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;
        
        for(int i=3; i<=n; ++i)
        {
            ways[i] = ways[i-1] + ways[i-2];
        }//for
        
        return ways[n];
        
    }
};
