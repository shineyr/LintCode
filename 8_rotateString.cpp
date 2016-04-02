/*
 8 旋转字符串

 描述
给定一个字符串和一个偏移量，根据偏移量旋转字符串(从左向右旋转)

样例
对于字符串 "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
挑战
在数组上原地旋转，使用O(1)的额外空间
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if(str.empty())
        {
            return ;
        }//if
        
        int len = str.size();
        offset %= len;
        
        reverse(str.begin(),str.begin()+len-offset);
        reverse(str.begin()+len-offset, str.end());
        reverse(str.begin(),str.end());
    }
};
