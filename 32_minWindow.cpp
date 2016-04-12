/*
32 最小子串覆盖

给定一个字符串source和一个目标字符串target，在字符串source中找到包括所有目标字符串字母的子串。
如果在source中没有这样的子串，返回""，如果有多个这样的子串，返回长度最小的子串。
说明
在答案的子串中的字母在目标字符串中是否需要具有相同的顺序？
——不需要。
样例
给出source = "ADOBECODEBANC"，target = "ABC" 满足要求的解  "BANC"
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param source: A string
	* @param target: A string
	* @return: A string denote the minimum window
	*          Return "" if there is no such a string
	*/
	string minWindow(string &source, string &target) {
		// write your code here
		if (source.empty() || target.empty())
			return "";

		int sLen = source.length(), tLen = target.length();
		vector<int> sHash(256, 0), tHash(256, 0);
		/*建立源串的映射，存储每个字符的出现次数*/
		for (int i = 0; i < tLen; ++i)
		{
			++tHash[target[i]];
		}//for

		/*记录符合要求的子串的位置，以及找到的字符个数*/
		int beg = -1, end = sLen, found = 0, minLen = sLen;
		for (int i = 0, start = i; i < sLen; ++i)
		{
			++sHash[source[i]];
			/*更新当前找到的字符个数*/
			if (sHash[source[i]] <= tHash[source[i]])
				++found;
			/*判断是否找到所有字符*/
			if (found == tLen)
			{
				/*将源串开头未出现在目标串的字符跳过*/
				while (start < i && sHash[source[start]] > tHash[source[start]])
				{
					--sHash[source[start]];
					++start;
				}//while
				/*找到符合要求子串的首尾位置start 与 i*/
				if (i - start < minLen)
				{
					minLen = i - start;
					beg = start;
					end = i;
				}//if
				/*跳过该子串的开头位置，寻找下一个子串*/
				--sHash[source[start++]];
				--found;
			}//if
		}//for

		/*如果beg值为-1，说明不存在这样的子串*/
		if (beg == -1)
			return "";
		else
			return source.substr(beg, end - beg + 1);
	}
};

int main()
{
	Solution s;
	string source = "ADOBECODEBANC", target = "BANC";

	cout << s.minWindow(source, target) << endl;

	system("pause");
	return 0;
}