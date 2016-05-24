/*
 53 翻转字符串

给定一个字符串，逐个翻转字符串中的每个单词。

说明
单词的构成：无空格字母构成一个单词
输入字符串是否包括前导或者尾随空格？可以包括，但是反转后的字符不能包括
如何处理两个单词间的多个空格？在反转字符串中间空格减少到只含一个
样例
给出s = "the sky is blue"，返回"blue is sky the"
*/

class Solution {
public:
	/**
	* @param s : A string
	* @return : A string
	*/
	string reverseWords(string s) {
		// write your code here
		if (s.empty())
		{
			return s;
		}//if

		int len = s.length(), i, beg;
		string ret = "";
		for (i = 0, beg = 0; i<len; ++i)
		{
			if (s[i] == ' ')
			{
				string tmp = s.substr(beg, i - beg);
				reverse(tmp.begin(), tmp.end());
				/*精确处理空格*/
				if (ret == "")
					ret += tmp;
				else
					ret = ret + " " + tmp;

				//寻找下一单词的开始位置
				while (s[i] == ' ')
				{
					++i;
				}//while
				beg = i;
			}//if

		}//for
		string tmp = s.substr(beg, i - beg);
		reverse(tmp.begin(), tmp.end());

		/*精确处理空格*/
		if (ret == "")
			ret += tmp;
		else if(tmp != "")
			ret = ret + " " + tmp;
        
		reverse(ret.begin(), ret.end());

		return ret;
	}
};
