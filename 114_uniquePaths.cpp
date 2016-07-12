/*
114 不同的路径

有一个机器人的位于一个M×N个网格左上角（下图中标记为'Start'）。

机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角（下图中标记为'Finish'）。
问有多少条不同的路径？
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if(m <=0 || n <= 0)
        {
            return 0;
        }
        // wirte your code here
        vector<vector<int>> paths(m,vector<int>(n,0));
        for(int i=0; i<m; ++i)
        {
            paths[i][0] = 1;
        }//for
        
        for(int j=0; j<n; ++j)
        {
            paths[0][j] = 1;
        }//for
        
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }//for
        }//for
        
        return paths[m-1][n-1];
    }
};
