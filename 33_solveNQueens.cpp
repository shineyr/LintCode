/*
33 N皇后问题

n皇后问题是将n个皇后放置在n*n的棋盘上，皇后彼此之间不能相互攻击。

给定一个整数n，返回所有不同的n皇后问题的解决方案。
每个解决方案包含一个明确的n皇后放置布局，其中“Q”和“.”分别表示一个女王和一个空位置。
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
	* Get all distinct N-Queen solutions
	* @param n: The number of queens
	* @return: All distinct solutions
	* For example, A string '...Q' shows a queen on forth position
	*/
	/*方法一、递归实现*/
	vector<vector<string> > solveNQueens1(int n) {
		// write your code here
		vector<vector<string>> solutions;
		/*用一维数组存储*/
		vector<int> queue(n, -1);
		/*用一维数组存储*/
		recursiveFun(solutions, queue, n, 0);
		return solutions;
	}

	/*递归实现*/
	void recursiveFun(vector<vector<string>> &solutions, vector<int> &queue, int n, int row)
	{
		if (row >= n)
		{
			vector<string> ret = getResult(queue);
			solutions.push_back(ret);
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
	vector<vector<string> > solveNQueens(int n) {
		// write your code here
		vector<vector<string>> solutions;
		/*用一维数组存储*/
		vector<int> queue(n, -1);
		int i = 0, j = 0;
		while(i < n)
		{
			while(j < n)
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
				vector<string> ret = getResult(queue);
				solutions.push_back(ret);

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

	/*将符合要求的结果用字符串数组表示*/
	vector<string> getResult(vector<int> queue)
	{
		if (queue.empty())
		{
			return vector<string>();
		}

		int len = queue.size();
		vector<string> ret(len, string(len,'.'));
		for (int i = 0; i < len; ++i)
		{
			ret[i][queue[i]] = 'Q';
		}//for
		return ret;
	}
};

int main()
{
	Solution s;
	vector<vector<string>> ret = s.solveNQueens1(4);

	for (auto iter1 = ret.begin(); iter1 != ret.end(); ++iter1)
	{
		for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2)
		{
			cout << *iter2 << endl;
		}//for
	}//for

	system("pause");
	return 0;
}