/*
63 搜索旋转排序数组 II

跟进“搜索旋转排序数组”，假如有重复元素又将如何？

是否会影响运行时间复杂度？

如何影响？

为何会影响？

写出一个函数判断给定的目标值是否出现在数组中。

样例
给出[3,4,4,5,7,0,1,2]和target=4，返回 true
*/

class Solution {
	/**
	* param A : an integer ratated sorted array and duplicates are allowed
	* param target :  an integer to be search
	* return : a boolean
	*/
public:
	bool search(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
		{
			return false;
		}//if

		int p = searchMin(A);
		bool ret = search1(A, target, 0, p - 1);
		return ret ? ret : search1(A, target, p, A.size() - 1);
	}

	/*旋转子数组中查找最小值*/
	int searchMin(vector<int> &A)
	{
		if (A.empty())
		{
			return -1;
		}//if

		int lhs = 0, rhs = A.size() - 1;
		if (A[lhs] < A[rhs])
		{
			return lhs;
		}//if

		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] >= A[rhs])
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

	bool search1(vector<int> &A, int target, int lhs, int rhs)
	{
		if (A.empty() || lhs > rhs)
		{
			return false;
		}//if

		while (lhs <= rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] == target)
			{
				return true;
			}//if
			else if (A[mid] > target)
			{
				rhs = mid - 1;
			}//elif
			else{
				lhs = mid + 1;
			}//else
		}//while

		return false;
	}
};