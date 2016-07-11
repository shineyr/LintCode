/*
142 O(1)时间检测2的幂次
用 O(1) 时间检测整数 n 是否是 2 的幂次。
O(1) 时间复杂度

样例
n=4，返回 true;

n=5，返回 false.
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
		// write your code here
		if(n <= 0)
		    return false;
		int ret = n & (n - 1);
		return ret == 0 ? true : false;
	}
};