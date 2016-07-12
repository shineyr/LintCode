/*
179 更新二进制位

给出两个32位的整数N和M，以及两个二进制位的位置i和j。写一个方法来使得N中的第i到j位等于M（M会是N中从第i为开始到第j位的子串）

样例
给出N = (10000000000)2，M = (10101)2， i = 2, j = 6

返回 N = (10001010100)2
*/
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        m <<= i;    
        int factor = 1;    
        
        factor <<= i;    
        int step = j-i+1;    
        while (step > 0)    
        {    
            n &= (~factor);    
            factor <<= 1;    
            step--;    
        }    
    
        return n ^ m; 
        
    }
};