/*
61 搜索区间

给定一个包含 n 个整数的排序数组，找出给定目标值 target 的起始和结束位置。

如果目标值不在数组中，则返回[-1, -1]

样例
给出[5, 7, 7, 8, 8, 10]和目标值target=8,

返回[3, 4]

*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> v;
        v.push_back(firstPos(A,target));
        v.push_back(lastPos(A,target));
        return v;
    }
    
    int firstPos(vector<int> &A , int target)
    {
        if(A.empty())
        {
            return -1;
        }//if
        
        int lhs = 0 , rhs = A.size()-1;
        while(lhs <= rhs)
        {
            int mid = (lhs + rhs)/2;
            if(A[mid] == target)
            {
                if(0 == mid)
                {
                    return mid;
                }//if
                else
                {
                    if( A[mid - 1] < target)
                    {
                        return mid;
                    }//if
                    else{
                        rhs = mid - 1;
                    }//else
                }//else
            }else if(A[mid] < target)
            {
                lhs = mid + 1;
            }//elif
            else{
                rhs = mid - 1;
            }//else
        }//while
        
        return -1;
    }
    
    int lastPos(vector<int> &A , int target)
    {
        if(A.empty())
        {
            return -1;
        }//if
        
        int lhs = 0 , rhs = A.size()-1;
        while(lhs <= rhs)
        {
            int mid = (lhs + rhs)/2;
            if(A[mid] == target)
            {
                if(mid == A.size()-1)
                {
                    return mid;
                }//if
                else{
                    if(A[mid + 1] > target)
                    {
                        return mid;
                    }else{
                        lhs = mid + 1;
                    }//else
                }//else
            }//if
            else if(A[mid] < target)
            {
                lhs = mid + 1;
            }//elif
            else{
                rhs = mid - 1;
            }//else
        }//while
        return -1;
    }
    
    
};