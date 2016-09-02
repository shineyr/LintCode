/*
192  通配符匹配 

判断两个可能包含通配符“？”和“*”的字符串是否匹配。匹配规则如下：

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。

两个串完全匹配才算匹配成功。

函数接口如下:
bool isMatch(const char *s, const char *p)

您在真实的面试中是否遇到过这个题？
样例

一些例子：

isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if(s == NULL && p == NULL)
            return true;
        if(s == NULL || p == NULL)
            return false;
            
            
        int sLen = strlen(s);
        int pLen = strlen(p);
        
        vector<vector<int>> dp(sLen+1,vector<int>(pLen+1,0));
        for(int i=1;i <=sLen ; ++i)
        {
            for(int j=1; j<=pLen; ++j)
            {
                dp[i][j] = 0;
            }//for
        }//for
        
        dp[0][0] = 1;
        for(int i=1; i<= sLen; ++i)
        {
            if(dp[i-1][0] == 1 && s[i-1] == '*')
            {
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
            }//else
        }//for
        
        for(int j=1; j<=pLen; ++j)
        {
            if(dp[0][j-1] == 1 && p[j-1] == '*')
            {
                dp[0][j] = 1;
            }else{
                dp[0][j] = 0;
            }//else
        }//for
        
        for(int i=1;i<=sLen; ++i)
        {
            for(int j=1; j<=pLen; ++j)
            {
                if(s[i-1] == '*' || p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else if(s[i-1] == '?' || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = ((s[i-1] == p[j-1] ? 1 : 0) && dp[i-1][j-1]);
                }//else
            }//for
        }//for
        
        return dp[sLen][pLen];
    }
};