/*
62 搜索旋转排序数组
假设有一个排序的按未知的旋转轴旋转的数组(比如，0 1 2 4 5 6 7 可能成为4 5 6 7 0 1 2)。给定一个目标值进行搜索，如果在数组中找到目标值返回数组中的索引位置，否则返回-1。

你可以假设数组中不存在重复的元素。

样例
给出[4, 5, 1, 2, 3]和target=1，返回 2

给出[4, 5, 1, 2, 3]和target=0，返回 -1
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
	/**
	* param A : an integer ratated sorted array
	* param target :  an integer to be searched
	* return : an integer
	*/
public:
	int search(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
		{
			return -1;
		}//if

		int p = searchMin(A);
		int ret = search1(A, target, 0, p - 1);
		return ret != -1 ? ret : search1(A, target, p, A.size() - 1);
	}

	/*旋转子数组中查找最小值*/
	int searchMin(vector<int> &A)
	{
		if (A.empty())
		{
			return -1;
		}//if

		int lhs = 0, rhs = A.size() - 1;
		if (A[lhs] <= A[rhs])
		{
			return lhs;
		}//if

		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] > A[rhs])
			{
				lhs = mid + 1;
			}//if
			else
			{
				rhs = mid;
			}//else
		}//while

		return lhs;
	}

	int search1(vector<int> &A, int target, int lhs, int rhs)
	{
		if (A.empty() || lhs > rhs)
		{
			return -1;
		}//if

		while (lhs <= rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] == target)
			{
				return mid;
			}//if
			else if (A[mid] > target)
			{
				rhs = mid - 1;
			}//elif
			else{
				lhs = mid + 1;
			}//else
		}//while

		return -1;
	}
};
int main()
{
	vector<int> v = { 4,5,1,2,3 };
	Solution s;
	cout << s.search(v, 0) << endl;

	system("pause");
	return 0;
}