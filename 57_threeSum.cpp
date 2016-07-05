/*
57 三数之和

给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。

在三元组(a, b, c)，要求a <= b <= c。

结果不能包含重复的三元组。

样例
如S = {-1 0 1 2 -1 -4}, 你需要返回的三元组集合的是：

(-1, 0, 1)

(-1, -1, 2)
*/
class Solution {
public:
	/**
	* @param numbers : Give an array numbers of n integer
	* @return : Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int> > threeSum(vector<int> &nums) {
		// write your code here
		vector<vector<int>> ret;
		if (nums.empty())
		{
			return ret;
		}//if

		int len = nums.size();


		for (int i = 0; i<len; ++i)
		{
			vector<int> tmp(nums.begin() + i + 1, nums.end());
			vector<vector<int>> r = twoSum(tmp, 0 - nums[i]);

			int n = r.size();
			for (int j = 0; j<n; ++j)
			{
				r[j].push_back(nums[i]);
				sort(r[j].begin(), r[j].end());
				ret.push_back(r[j]);
			}//for
		}//for
		//去重
		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());
		return ret;
	}

	vector<vector<int>> twoSum(vector<int> &nums, int target)
	{
		vector<vector<int>> ret;
		if (nums.empty())
		{
			return ret;
		}//if

		int len = nums.size();
		for (int i = 0; i<len; ++i)
		{
			for (int j = i + 1; j<len; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[j]);

					sort(v.begin(), v.end());
					ret.push_back(v);
				}//if
			}//for
		}//for
		return ret;
	}
};