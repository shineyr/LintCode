/*
171 乱序字符串

给出一个字符串数组S，找到其中所有的乱序字符串(Anagram)。如果一个字符串是乱序字符串，那么他存在一个字母集合相同，但顺序不同的字符串也在S中。

所有的字符串都只包含小写字母

样例
对于字符串数组 ["lint","intl","inlt","code"]

返回 ["lint","inlt","intl"]
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        if(strs.empty())
        {
            return vector<string>();
        }//if
        
        int len = strs.size();
        
        map<string,int> m;
        for(int i=0; i<len; ++i)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            m[t]++;
        }//for
        
        vector<string> ret;
        for(int i=0;i<len;++i)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            if(m[t] > 1)
            {
                ret.push_back(strs[i]);
            }//if
        }//for
        return ret;
    }
    
   
};
