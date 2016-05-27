/*
84 落单的数 III

 描述
 笔记
 数据
 评测
给出2*n + 2个的数字，除其中两个数字之外其他每个数字均出现两次，找到这两个数字。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 [1,2,2,3,4,4,5,3]，返回 1和5
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param A : An integer array
	* @return : Two integers
	*/
	vector<int> singleNumberIII(vector<int> &A) {
		// write your code here
		if (A.empty())
		{
			return vector<int>();
		}//if

		int n = A.size();
		int pos = findFirstPos(A);

		vector<int> v1, v2, ret;
		for (int i = 0; i<n; ++i)
		{
			int tmp = A[i] >> pos;
			if (tmp & 0x1 != 0)
			{
				v1.push_back(A[i]);
			}//if
			else {
				v2.push_back(A[i]);
			}//else
		}//for
		ret.push_back(singleNumber(v1));
		ret.push_back(singleNumber(v2));

		return ret;
	}

	int findFirstPos(vector<int> &A)
	{
		if (A.empty())
		{
			return -1;
		}//if

		int n = A.size();
		int ret = 0;
		for (int i = 0; i<n; ++i)
		{
			ret ^= A[i];
		}//for

		for (int i = 0; i<32; ++i)
		{
			int tmp = ret >> i;
			if (tmp & 0x1 != 0)
			{
				return i;
			}//if
		}//for

	}//int

	int singleNumber(vector<int> &A) {
		// write your code here
		if (A.empty())
		{
			return 0;
		}//if

		int ret = 0;
		for (auto iter = A.begin(); iter != A.end(); ++iter)
		{
			ret ^= (*iter);
		}//for

		return ret;
	}

};

int main()
{
	vector<int> v = { 1,2,2,3,4,4,5,3 };

	Solution s;
	vector<int> ret = s.singleNumberIII(v);

	cout << ret[0] << ret[1] << endl;
	system("pause");
	return 0;
}