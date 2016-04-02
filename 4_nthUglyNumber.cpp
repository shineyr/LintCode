/*
4. 丑数

题目：设计一个算法，找出只含素因子2，3，5 的第 n 大的数。

符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

样例
如果n = 9， 返回 10

挑战
要求时间复杂度为O(nlogn)或者O(n)

*/

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        if(n <= 0)
        {
            return 0;
        }
        else if(n == 1)
        {
            return 1;
        }//if
        
        /*存储丑数数组*/
        vector<int> uglyNums(n+1,0);
        uglyNums[0] = 1;
        
        auto iter2 = uglyNums.begin(),iter3 = uglyNums.begin(),iter5 = uglyNums.begin();
        
        int idx = 1;
        while(idx < n)
        {
            int minNum = min(min(*iter2 * 2 , *iter3 * 3) , *iter5 * 5);
            uglyNums[idx] = minNum;
            while(*iter2 * 2 <= uglyNums[idx])
            {
                ++iter2;
            }//while
            
            while(*iter3 * 3 <= uglyNums[idx])
            {
                ++iter3;
            }//while
            
            while(*iter5 * 5 <= uglyNums[idx])
            {
                ++iter5;
            }//while
            
            ++idx;
        }//while
        
        return uglyNums[n-1];
    }
};