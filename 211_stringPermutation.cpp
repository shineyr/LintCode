/*
211 字符串置换

给定两个字符串，请设计一个方法来判定其中一个字符串是否为另一个字符串的置换。

置换的意思是，通过改变顺序可以使得两个字符串相等。

样例
"abc" 为 "cba" 的置换。

"aabc" 不是 "abcc" 的置换。
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        return A == B;
    }
};