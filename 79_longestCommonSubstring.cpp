/*
79 最长公共子串

给出两个字符串，找到最长公共子串，并返回其长度。

注意事项
子串的字符应该连续的出现在原字符串中，这与子序列有所不同。

样例

给出A=“ABCD”，B=“CBCE”，返回 2

*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if(A.empty() || B.empty())
        {
            return 0;
        }//if
        
        int aLen = A.size(), bLen = B.size();
        /*动态规划，时间复杂度O(mn) 空间复杂度O(mn）
        dp[i][j]表示必须把A[i]和B[j]作为公共子串的最后一个字符时的子串最大长度*/
        vector<vector<int>> dp(aLen, vector<int>(bLen,0));
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        
        int maxLen = dp[0][0];
        
        for(int i=1; i<aLen; ++i)
        {
            dp[i][0] = A[i] == B[0] ? 1 : 0;
            maxLen = max(maxLen, dp[i][0]);
        }//for
        
        for(int j=1; j<bLen; ++j)
        {
            dp[0][j] = A[0] == B[j] ? 1 : 0;
            
            maxLen = max(maxLen, dp[0][j]);
        }//for
        
        
        for(int i=1; i<aLen; ++i)
        {
            for(int j=1; j<bLen; ++j)
            {
                if(A[i] == B[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }//if
                else{
                    dp[i][j] = 0;
                }//if
                
                maxLen = max(maxLen, dp[i][j]);
            }//for
        }//for
        return maxLen;
    }
};
