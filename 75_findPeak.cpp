/*
75 寻找峰值

你给出一个整数数组(size为n)，其具有以下特点：

    相邻位置的数字是不同的
    A[0] < A[1] 并且 A[n - 2] > A[n - 1]

假定P是峰值的位置则满足A[P] > A[P-1]且A[P] > A[P+1]，返回数组中任意一个峰值的位置。
注意事项

数组可能包含多个峰值，只需找到其中的任何一个即可
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if(A.empty())
        {
            return -1;
        }//if
    
        for(int i=1; i<A.size()-1; ++i)
        {
            if(A[i] > A[i-1] && A[i] > A[i+1])
            {
                return i;
            }//if
        }//for
        
        return -1;
    }
};
