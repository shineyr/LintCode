/*
366 斐波纳契数列

查找斐波纳契数列中第 N 个数。

所谓的斐波纳契数列是指：

前2个数是 0 和 1 。
第 i 个数是第 i-1 个数和第i-2 个数的和。
斐波纳契数列的前10个数字是：

0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

您在真实的面试中是否遇到过这个题？ Yes
样例
给定 1，返回 0

给定 2，返回 1

给定 10，返回 34
*/
class Solution {
public:
	/**
	* @param n: an integer
	* @return an integer f(n)
	*/
	int fibonacci(int n) {
		// write your code here
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else {
			long long lastOne = 1;
			long long lastTwo = 0;

			long long retN = 0;
			for (int i = 3; i <= n; ++i)
			{
				retN = lastOne + lastTwo;

				lastTwo = lastOne;
				lastOne = retN;
			}
			return retN;
		}
	}

	int fibonacci1(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else {
			return fibonacci1(n - 1) + fibonacci1(n - 2);
		}
	}

	int fibonacci2(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else {
			vector<int> ret(n + 1,0);
			ret[1] = 0;
			ret[2] = 1;
			for (int i = 3; i <= n; ++i)
			{
				ret[i] = ret[i - 1] + ret[i - 2];
			}//for
			return ret[n];
		}
	}
};