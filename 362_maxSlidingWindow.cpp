/*
362  滑动窗口的最大值

给出一个可能包含重复的整数数组，和一个大小为 k 的滑动窗口, 从左到右在数组中滑动这个窗口，找到数组中每个窗口内的最大值。

样例
给出数组 [1,2,7,7,8], 滑动窗口大小为 k = 3. 返回 [7,7,8].

解释：

最开始，窗口的状态如下：

[|1, 2 ,7| ,7 , 8], 最大值为 7;

然后窗口向右移动一位：

[1, |2, 7, 7|, 8], 最大值为 7;

最后窗口再向右移动一位：

[1, 2, |7, 7, 8|], 最大值为 8.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: The maximum number inside the window at each moving.
	*/
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty() || nums.size() < k)
		{
			return vector<int>();
		}

		int n = nums.size();
		vector<int> ret;
		deque<int> idx;
		/**/
		for (int i = 0; i < k; ++i)
		{
			while (!idx.empty() && nums[i] >= nums[idx.back()])
			{
				idx.pop_back();
			}//while
			idx.push_back(i);
		}

		for (int i = k; i < n; ++i)
		{
			ret.push_back(nums[idx.front()]);

			while (!idx.empty() && nums[i] >= nums[idx.back()])
				idx.pop_back();

			if (!idx.empty() && idx.front() <= (i - k))
				idx.pop_front();

			idx.push_back(i);
		}
		ret.push_back(nums[idx.front()]);

		return ret;
	}
	/*O(n^2)解法*/
	vector<int> maxSlidingWindow1(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty())
		{
			return vector<int>();
		}

		int n = nums.size();
		vector<int> ret;
		for (int i = 0; i<n - k + 1; ++i)
		{
			int maxNum = nums[i];
			for (int j = i + 1; j<i + k; ++j)
			{
				if (maxNum < nums[j])
				{
					maxNum = nums[j];
				}//if
			}//for

			ret.push_back(maxNum);
		}//for

		return ret;
	}
};

int main()
{
	vector<int> v = { 1,2,7,7,2 };

	vector<int> ret = Solution().maxSlidingWindow(v, 3);

	system("pause");
	return 0;
}