/*
18  带重复元素的子集
给定一个可能具有重复数字的列表，返回其所有可能的子集

样例
如果 S = [1,2,2]，一个可能的答案为：

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > subsetsWithDup(const vector<int> &S) {
		// write your code here
		if (S.empty())
		{
			return vector<vector<int>>(1, vector<int>());
		}//if

		vector<int> nums(S.begin(), S.end());
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<int> tmp(nums.begin(), nums.begin() + len - 1);
		vector<vector<int>> tmpSets = subsetsWithDup(tmp);

		vector<vector<int>> ret;
		int tmpLen = tmpSets.size();
		for (int i = 0; i<tmpLen; ++i)
		{				
			vector<int> tmp = tmpSets[i];
			ret.push_back(tmp);
			tmp.push_back(nums[len - 1]);
			/*去重*/
			if (find(tmpSets.begin(), tmpSets.end(), tmp) == tmpSets.end())
				ret.push_back(tmp);

		}//for

		return ret;
	}

	/*非递归实现*/
	vector<vector<int> > subsetsWithDup2(const vector<int> &S) {
		// write your code here
		if (S.empty())
		{
			return vector<vector<int>>(1, vector<int>());
		}//if
		vector<int> nums(S.begin(), S.end());
		sort(nums.begin(), nums.end());

		int len = nums.size();
		vector<vector<int>> ret;
		ret.push_back(vector<int>());
		for (int i = 0; i < len; ++i)
		{
			int tmpLen = ret.size();
			for (int j = 0; j < tmpLen;++j)
			{
				vector<int> tmp = ret[j];
				tmp.push_back(nums[i]);
				/*去重*/
				if (find(ret.begin(), ret.end(), tmp) == ret.end())
					ret.push_back(tmp);
			}//for
		}//for

		return ret;
	}
};
