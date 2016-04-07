/*
18  搜索二维矩阵
写出一个高效的算法来搜索 m × n矩阵中的值。

这个矩阵具有以下特性：

每行中的整数从左到右是排序的。
每行的第一个数大于上一行的最后一个整数。

样例
考虑下列矩阵：

[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
给出 target = 3，返回 true
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty())
        {
            return false;
        }//if
        
        int m = matrix.size() , n = matrix[0].size();
        int row = 0 , col = n-1;
        while(row < m && col >= 0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }//if
            else if(matrix[row][col] < target)
            {
                ++row;
            }else{
                --col;
            }//else
        }//while
        
        return false;
    }
};
