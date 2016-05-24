/*
48 主元素 III

给定一个整型数组，找到主元素，它在数组中的出现次数严格大于数组元素个数的1/k。

样例
给出数组 [3,1,2,3,2,3,3,4,4,4] ，和 k = 3，返回 3
*/
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @param k: As described
	* @return: The majority number
	*/
	int majorityNumber(vector<int> nums, int k) {
		// write your code here
		int n = nums.size();

		vector<int> vals(k - 1, INT_MIN), times(k - 1, 0);

		for (int i = 0; i<n; ++i)
		{
			int tmp = nums[i];
			bool flag = false;
			/*与k-1个关键字比较，更新重复次数*/
			if (!flag)
			{
				for (int j = 0; j < k - 1; ++j)
				{
					if (tmp == vals[j])
					{
						++times[j];
						flag = true;
						break;
					}//if
				}//for
			}
			
			if (!flag)
			{
				for (int j = 0; j < k - 1; ++j)
				{
					if (times[j] == 0)
					{
						vals[j] = tmp;
						times[j] = 1;
						flag = true;
						break;
					}//if
				}//for
			}//if
			
			if (!flag)
			{
				for (int j = 0; j < k - 1; ++j)
				{
					--times[j];
				}//for
			}//if
			
		}//for

		/*清0 k-1个关键字次数*/
		for (int j = 0; j<k - 1; ++j)
		{
			times[j] = 0;
		}//for

		/*记录每个关键字的实际次数*/
		for (int i = 0; i<n; ++i)
		{
			int tmp = nums[i];
			for (int j = 0; j<k - 1; ++j)
			{
				if (tmp == vals[j])
				{
					++times[j];
					break;
				}//if
			}//for
		}//for

		/*出现次数最多的便是1/k的主元素*/
		int pos = -1, maxTimes = 0;
		for (int j = 0; j<k - 1; ++j)
		{
			if (times[j] > maxTimes)
			{
				maxTimes = times[j];
				pos = j;
			}//if
		}//for

		return vals[pos];
	}
};

int main()
{
	vector<int> v = { 3,1,2,3,2,3,3,4,4,4 };
	Solution s;
	cout << s.majorityNumber(v, 3) << endl;

	system("pause");
	return 0;
}