/*
 38 搜索二维矩阵 II

写出一个高效的算法来搜索m×n矩阵中的值，返回这个值出现的次数。

这个矩阵具有以下特性：

每行中的整数从左到右是排序的。
每一列的整数从上到下是排序的。
在每一行或每一列中没有重复的整数。

样例
考虑下列矩阵：

[

    [1, 3, 5, 7],

    [2, 4, 7, 8],

    [3, 5, 9, 10]

]

给出target = 3，返回 2

挑战
要求O(m+n) 时间复杂度和O(1) 额外空间
*/
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty())
        {
            return 0;
        }//if
        
        int m = matrix.size(),n=matrix[0].size();
        int r=0,c=n-1, count=0;
        while(r < m && c >= 0)
        { 
            if(matrix[r][c] == target)
            {
                ++count;
                ++r;
                --c;
            }//if
            else if(matrix[r][c] < target)
            {
                ++r;
            }else{
                --c;
            }//else
        }//while
        
        return count;
    }
};
