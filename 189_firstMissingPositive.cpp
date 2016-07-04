/*
189 丢失的第一个正整数

给出一个无序的正数数组，找出其中没有出现的最小正整数。

样例
如果给出 [1,2,0], return 3
如果给出 [3,4,-1,1], return 2
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        if(A.empty())
        {
            return 1;
        }//if
        
        set<int> s(A.begin(),A.end());
        
        int cur = 1;
        
        for(auto iter=s.begin(); iter!=s.end(); ++iter)
        {
            if(*iter <= 0)
            {
                continue;
            }//if
            else if(*iter != cur)
            {
                return cur;
            }else{
                cur++;
            }//else
        }//for
        return cur;
        
    }
};