/*
 55 比较字符串

比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母

在 A 中出现的 B 字符串里的字符不需要连续或者有序。

样例
给出 A = "ABCD" B = "ACD"，返回 true

给出 A = "ABCD" B = "AABC"， 返回 false
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if(B.empty())
        {
            return true;
        }//if
        
        int lA = A.length() , lB = B.length();
        vector<int> v(256,0);
        for(int i=0; i<lA; ++i)
        {
            ++v[A[i]];
        }//for
        
        for(int j=0; j<lB; ++j)
        {
            --v[B[j]];
            if(v[B[j]] < 0)
            {
                return false;
            }//if
        }//for
        
        return true;
    }
};
