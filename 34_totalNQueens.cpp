/*
34 N皇后问题 II

根据n皇后问题，现在返回n皇后不同的解决方案的数量而不是具体的放置布局。
样例
比如n=4，存在2种解决方案
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* Calculate the total number of distinct N-Queen solutions.
	* @param n: The number of queens.
	* @return: The total number of distinct solutions.
	*/
	int totalNQueens1(int n) {
		// write your code here
		int solutions = 0;
		/*用一维数组存储*/
		vector<int> queue(n, -1);
		/*用一维数组存储*/
		recursiveFun(solutions, queue, n, 0);
		return solutions;
	}

	/*递归实现*/
	void recursiveFun(int &solutions, vector<int> &queue, int n, int row)
	{
		if (row >= n)
		{
			++solutions;
		}//if
		else{
			for (int j = 0; j < n; ++j)
			{
				/*递归在上一个任务成功后*/
				if (isValid(queue, row, j))
				{
					queue[row] = j;
					recursiveFun(solutions, queue, n, row + 1);
				}//if
			}//else
		}//else
	}

	/*方法二、非递归实现*/
	int totalNQueens(int n) {
		// write your code here
		int solutions = 0;
		/*用一维数组存储*/
		vector<int> queue(n, -1);
		int i = 0, j = 0;
		while (i < n)
		{
			while (j < n)
			{
				if (isValid(queue, i, j))
				{
					/*第i行的皇后的列为j*/
					queue[i] = j;

					/*继续探测下一个皇后的位置*/
					j = 0;
					break;
				}//if
				else{
					++j;
				}//else
			}//while

			/*第i行没有找到可以放置皇后的位置，说明该方案不可行*/
			if (-1 == queue[i])
			{
				/*当前没有可行解的行标为0，说明已经找完所有的解*/
				if (0 == i)
				{
					break;
				}//if
				/*回溯到上一行*/
				else
				{
					--i;
					/*改变上一行皇后的位置*/
					j = queue[i] + 1;
					queue[i] = -1;
					continue;
				}//else
			}//if

			/*找到一个可行解*/
			if (i == n - 1)
			{
				++solutions;

				/*不能在此处结束程序，因为我们要找的是N皇后问题的所有解，此时应该清除该行的皇后，
				从当前放置皇后列数的下一列继续探测。*/
				j = queue[i] + 1;
				queue[i] = -1;
				continue;
			}//if
			++i;
		}//while
		return solutions;
	}


	/*判断在r行c列放置皇后，是否合法*/
	bool isValid(vector<int> queue, int r, int c)
	{
		if (queue.empty())
			return true;
		for (int i = 0; i < r; ++i)
		{
			if (queue[i] == c || abs(i - r) == abs(queue[i] - c))
				return false;
		}//for
		return true;
	}
};


int main()
{
	Solution s;
	cout << s.totalNQueens1(4) << endl;

	

	system("pause");
	return 0;
}