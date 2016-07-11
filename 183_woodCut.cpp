/*
183 木材加工

有一些原木，现在想把这些木头切割成一些长度相同的小段木头，需要得到的小段的数目至少为 k。当然，我们希望得到的小段越长越好，你需要计算能够得到的小段木头的最大长度。

木头长度的单位是厘米。原木的长度都是正整数，我们要求切割得到的小段木头的长度也要求是整数。无法切出要求至少 k 段的,则返回 0 即可。

样例
有3根木头[232, 124, 456], k=7, 最大长度为114.
*/

class Solution {
public:
	/**
	*@param L: Given n pieces of wood with length L[i]
	*@param k: An integer
	*return: The maximum length of the small pieces.
	*/
	int woodCut(vector<int> L, int k) {
		// write your code here
		if (L.empty() || k <= 0)
		{
			return 0;
		}//if

		long long sumLen = 0;
		int len = L.size();
		for (int i = 0; i<len; ++i)
		{
			sumLen += L[i];
		}//for

		if (sumLen < k)
		{
			return 0;
		}//if

		int maxLen = *max_element(L.begin(), L.end());
		int l = 1, r = maxLen;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (judge(L, mid, k))
			{
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}//else

		}//while
		return (int)r;
	}

	bool judge(vector<int> L, int mid, int k)
	{
		if (L.empty() || k <= 0)
		{
			return 0;
		}//if

		int count = 0, len = L.size();
		for (int i = 0; i<len; ++i)
		{
			count += L[i] / mid;
		}//for

		if (count >= k)
			return true;
		else
			return false;
	}
};