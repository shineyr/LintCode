/*
381 螺旋矩阵 II

给你一个数n生成一个包含1-n^2的螺旋形矩阵

样例
n = 3
矩阵为

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        if(n <= 0)
        {
            return vector<vector<int>>();
        }//if
        vector<vector<int>> ret(n,vector<int>(n,0)); 
        
        int tr=0,tc=0,idx=0;
        while(tr<n && tc < n)
        {
            for(int j=tr;j<=n-1;++j)
            {
                ret[tr][j] = ++idx;
            }//for
            
            if(tr<n-1)
            {
                for(int i=tr+1;i<=n-1;++i)
                {
                    ret[i][n-1] = ++idx;
                }//for
            }//if
            
            if(tr<n-1 && tc<n-1)
            {
                for(int j=n-2;j>=tc;--j)
                {
                    ret[n-1][j] = ++idx;
                }//for
            }//if
            
            if(tr<n-2)
            {
                for(int i=n-2;i>tr;--i)
                {
                    ret[i][tc] = ++idx;
                }//for
            }//if
            
            --n;
            ++tr;
            ++tc;
        }
        
        return ret;
    }
};