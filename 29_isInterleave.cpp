/*
29 交叉字符串

给出三个字符串:s1、s2、s3，判断s3是否由s1和s2交叉构成。

比如 s1 = "aabcc" s2 = "dbbca"

    - 当 s3 = "aadbbcbcac"，返回  true.

    - 当 s3 = "aadbbbaccc"， 返回 false.
*/
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if(s1.empty())
        {
            return s2 == s3;
        }//if
        else if(s2.empty())
        {
            return s1 == s3;
        }//elif
        else{
            int l1=s1.size(),l2=s2.size(),l3=s3.size();
            
            if(l3 != l1 + l2)
                return false;
             
            /*动态规划*/
            vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
            dp[0][0] = 1;
            for(int i=1; i<=l1; ++i)
            {
                if(dp[i-1][0] == 1 && s3[i-1] == s1[i-1])
                {
                    dp[i][0] = 1;
                }//if
            }//for
            
            for(int j=1; j<=l2; ++j)
            {
                if(dp[0][j-1] == 1 && s3[j-1] == s2[j-1])
                {
                    dp[0][j] = 1;
                }//for
            }//for
            
            for(int i=1; i<=l1; ++i)
            {
                for(int j=1; j<=l2; ++j)
                {
                    int t = i+j;  
                    if(s1[i-1]==s3[t-1])  
                        dp[i][j] = dp[i][j]||dp[i-1][j] ? 1 : 0;  
                    if(s2[j-1]==s3[t-1])  
                        dp[i][j] = dp[i][j]||dp[i][j-1] ? 1 : 0; 
                }//for
            }//for
            return dp[l1][l2];
        }//else
    }
};