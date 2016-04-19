/*
 49 字符大小写排序

给定一个只包含字母的字符串，按照先小写字母后大写字母的顺序进行排序。


小写字母或者大写字母他们之间不一定要保持在原始字符串中的相对位置。

样例
给出"abAcD"，答案为"abcAD"
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;


class Solution {
public:
	/**
	* @param chars: The letters array you should sort.
	*/
	void sortLetters(string &letters) {
		// write your code here
		if (letters.empty())
		{
			return;
		}//if

		int lhs = 0, rhs = letters.length() - 1;
		while (lhs <= rhs)
		{
			while (letters[lhs] >= 'a' && letters[lhs] <= 'z')
			{
				++lhs;
			}//while

			while (letters[rhs] >= 'A' && letters[rhs] <= 'Z')
			{
				--rhs;
			}//while
			if (lhs < rhs)
			{
				char c = letters[lhs];
				letters[lhs] = letters[rhs];
				letters[rhs] = c;
			}//if
		}//while

		string str1 = letters.substr(0, lhs);
		sort(str1.begin(), str1.end());

		string str2 = letters.substr(lhs);
		sort(str2.begin(), str2.end());

		letters = str1 + str2;
	}
};

int main()
{
	Solution s;

	string str = "DERLKAJKFKLAJFKAKLFJKLJFa";
	s.sortLetters(str);

	cout << str << endl;

	system("pause");
	return 0;

}