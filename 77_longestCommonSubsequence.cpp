/*
77 最长公共子序列

给出两个字符串，找到最长公共子序列(LCS)，返回LCS的长度。

说明

最长公共子序列的定义：

    最长公共子序列问题是在一组序列（通常2个）中找到最长公共子序列（注意：不同于子串，LCS不需要是连续的子串）。该问题是典型的计算机科学问题，是文件差异比较程序的基础，在生物信息学中也有所应用。
    https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

样例

给出"ABCD" 和 "EDCA"，这个LCS是 "A" (或 D或C)，返回1

给出 "ABCD" 和 "EACB"，这个LCS是"AC"返回 2
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        
        if(A.empty() || B.empty())
        {
            return 0;
        }//if
        
        int aLen = A.size(), bLen = B.size();
        
        /*矩阵dp[i][j]的含义是字符串A[0...i]与字符串B[0...j]的最长公共子序列长度，从左到右，从上到下计算矩阵dp*/
        vector<vector<int>> dp(aLen, vector<int>(bLen, 0));
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        for(int i=1; i<aLen; ++i)
        {
            dp[i][0] = max(dp[i-1][0], A[i] == B[0] ? 1 : 0);
        }//for
        
        for(int j=1; j<bLen; ++j)
        {
            dp[0][j] = max(dp[0][j], A[0] == B[j] ? 1 : 0);
        }//for
        
        for(int i=1; i<aLen; ++i)
        {
            for(int j=1; j<bLen; ++j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
                if(A[i] == B[j])
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }//if
            }//for
        }//for
        
        return dp[aLen-1][bLen-1];
    }
};
