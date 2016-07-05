/*
141 x的平方根

实现 int sqrt(int x) 函数，计算并返回 x 的平方根。

样例
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3
*/

class Solution {
public:
	/**
	* @param x: An integer
	* @return: The sqrt of x
	*/
	int sqrt(int x) {
		// write your code here
		long long lhs = 0, rhs = x / 2 + 1;
		while (lhs <= rhs)
		{
			long long mid = (lhs + rhs) / 2;

			long long tmp = mid * mid;
			if (static_cast<long long>(x) == tmp)
			{
				return mid;
			}//if
			else if (static_cast<long long>(x) > tmp)
			{
				long long tmp2 = (mid + 1)*(mid + 1);
				if(static_cast<long long>(x) < tmp2)
					return mid;
				else
					lhs = mid + 1;
			}//elif
			else {
				rhs = mid - 1;
			}//else
		}//while

		return -1;
	}
};
