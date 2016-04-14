/*
 39 恢复旋转排序数组

给定一个旋转排序数组，在原地恢复其排序。

说明
什么是旋转数组？

比如，原始数组为[1,2,3,4], 则其旋转数组可以是[1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
样例
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

挑战
使用O(1)的额外空间和O(n)时间复杂度
*/
class Solution {
public:
	void recoverRotatedSortedArray(vector<int> &nums) {
		// write your code here
		if (nums.empty())
		{
			return;
		}//if

		int len = nums.size();
		int minNum = nums[0], minIdx = 0;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i] < minNum)
			{
				minNum = nums[i];
				minIdx = i;
			}//if
		}//for

		if (minIdx == 0)
		{
			return;
		}//if

		reverse(nums, 0, minIdx - 1);
		reverse(nums, minIdx, len - 1);
		reverse(nums, 0, len - 1);
		return;
	}

	void reverse(vector<int> &nums, int beg, int end)
	{
		if (nums.empty() || beg >= end)
		{
			return;
		}//if

		while (beg < end)
		{
			exchange(nums[beg++], nums[end--]);
		}//while
	}

	void exchange(int &a, int &b)
	{
		if (a == b)
		{
			return;
		}//if

		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
};