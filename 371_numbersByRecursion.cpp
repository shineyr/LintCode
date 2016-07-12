/*
371 用递归打印数字

用递归的方法找到从1到最大的N位整数。

 注意事项

用下面这种方式去递归其实很容易：

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
但是这种方式会耗费很多的递归空间，导致堆栈溢出。你能够用其他的方式来递归使得递归的深度最多只有 N 层么？

样例
给出 N = 1, 返回[1,2,3,4,5,6,7,8,9].

给出 N = 2, 返回[1,2,3,4,5,6,7,8,9,10,11,...,99].
*/

class Solution {
public:
	/**
	* @param n: An integer.
	* return : An array storing 1 to the largest number with n digits.
	*/
	vector<int> numbersByRecursion(int n) {
		// write your code here
		if (n == 0)
		{
			return vector<int>();
		}
		else if (n == 1) {
			vector<int> ret = { 1,2,3,4,5,6,7,8,9 };
			return ret;
		}
		else {
			vector<int> last = numbersByRecursion(n - 1);
			vector<int> ret = { 1,2,3,4,5,6,7,8,9 };

			for (vector<int>::iterator iter = last.begin(); iter != last.end(); ++iter)
			{
				for (int i = 0; i <= 9; ++i)
				{
					ret.push_back(*iter * 10 + i);
				}//for

			}//for
			return ret;
		}
	}
};