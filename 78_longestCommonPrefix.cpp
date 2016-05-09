/*
78 最长公共前缀

给k个字符串，求出他们的最长公共前缀(LCP)

样例

在 "ABCD" "ABEF" 和 "ACEF" 中,  LCP 为 "A"

在 "ABCDEFG", "ABCEFG", "ABCEFA" 中, LCP 为 "ABC"

*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
     //两两计算前缀
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if(strs.empty())
        {
            return "";
        }//if
        
        int n = strs.size();
        string pRet = strs[0];
        
        for(int i=1; i<n; ++i)
        {
            string tmp = pRet;
            pRet = "";
            
            int len = min(tmp.length() , strs[i].length());
            for(int j=0; j<len; ++j)
            {
                if(tmp[j] == strs[i][j])
                {
                    pRet += tmp[j];
                }//if
                else
                {
                    break;
                }//else
            }//for
            
        }//for
        
        return pRet;
    }
};