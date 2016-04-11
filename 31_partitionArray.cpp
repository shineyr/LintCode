/*
给出一个整数数组nums和一个整数k。划分数组（即移动数组nums中的元素），使得：

所有小于k的元素移到左边
所有大于等于k的元素移到右边
返回数组划分的位置，即数组中第一个位置i，满足nums[i]大于等于k。

样例
给出数组nums=[3,2,2,1]和 k=2，返回 1
*/
class Solution {
public:

    /*方法一，利用快速排序的思想*/
	int partitionArray1(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty())
		{
			return 0;
		}//if

		return partition(nums, 0, nums.size() - 1, k);
	}

    /*方法二，就地交换*/
	int partitionArray(vector<int> &nums, int k)
	{
		if (nums.empty())
			return 0;

		int lhs = 0, rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			while (lhs < nums.size() && nums[lhs] < k)
			{
				++lhs;
			}//while
			while (rhs >=0 && nums[rhs] >= k)
			{
				--rhs;
			}//while
			if (lhs < rhs)
			{
				exchange(nums[lhs], nums[rhs]);
			}//if
		}//for

		return rhs+1;
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

	int partition(vector<int> &nums, int low, int high, int k)
	{
		if (nums.empty() || low > high || high >= nums.size())
		{
			return -1;
		}//if
		int left = -1, x = k;
		for (int i = low; i <= high; ++i)
		{
			if (nums[i] < x)
			{
				++left;
				exchange(nums[left], nums[i]);
			}//if
		}//for

		return left + 1;
	}

};