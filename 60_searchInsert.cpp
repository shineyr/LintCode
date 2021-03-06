/*
60 搜索插入位置
给定一个排序数组和一个目标值，如果在数组中找到目标值则返回索引。如果没有，返回到它将会被按顺序插入的位置。

你可以假设在数组中无重复元素。

样例
[1,3,5,6]，5 → 2

[1,3,5,6]，2 → 1

[1,3,5,6]， 7 → 4

[1,3,5,6]，0 → 0
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
	/**
	* param A : an integer sorted array
	* param target :  an integer to be inserted
	* return : an integer
	*/
public:
	int searchInsert(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
		{
			return 0;
		}//if

		int lhs = 0, rhs = A.size() - 1;
		while (lhs <= rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] == target)
			{
				return mid;
			}//if
			else if (A[mid] < target)
			{
				lhs = mid + 1;
			}//elif
			else{
				rhs = mid - 1;
			}//else
		}//while

		return rhs + 1;
	}
};

int main()
{
	vector<int> v = { 1, 3, 5, 6, 8, 9 };
	Solution s;
	cout << s.searchInsert(v, 10) << endl;

	system("pause");
	return 0;
}