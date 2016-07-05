/*
59 最接近的三数之和

给一个包含 n 个整数的数组 S, 找到和与给定整数 target 最接近的三元组，返回这三个数的和。

只需要返回三元组之和，无需返回三元组本身

样例
例如 S = [-1, 2, 1, -4] and target = 1. 和最接近 1 的三元组是 -1 + 2 + 1 = 2.
*/
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @param target: An integer
	* @return: return the sum of the three integers, the sum closest target.
	*/
	int threeSumClosest(vector<int> nums, int target) {
		// write your code here
		if (nums.empty())
		{
			return 0;
		}

		int len = nums.size(), minR = nums[0] + nums[1] + nums[2];
		for (int i = 0; i<len; ++i)
		{
			for (int j = i + 1; j<len; ++j)
			{
				for (int k = j + 1; k<len; ++k)
				{
					int tmpSum = nums[i] + nums[j] + nums[k];

					if (abs(minR - target) >= abs(target - tmpSum))
					{
						minR = tmpSum;
					}//if
				}//for
			}//for
		}//for

		return minR;
	}
};
