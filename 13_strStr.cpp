/*
13 字符串查找

对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。如果不存在，则返回 -1。

样例
如果 source = "source" 和 target = "target"，返回 -1。

如果 source = "abcdabcdefg" 和 target = "bcd"，返回 1。
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == NULL || target == NULL)
        {
            return -1;
        }//if

        /*普通模式匹配算法*/
        int sLen = strlen(source),tLen = strlen(target);
        
        int i=0,j=0;
        while(i<sLen && j<tLen)
        {
            if(source[i] == target[j])
            {
                ++i;
                ++j;
            }//if
            else{
                i = i - j + 1;
                j = 0;
            }
        }
        
        if(j >= tLen)
        {
            return i-tLen;
        }else{
            return -1;
        }
    }
    
    
};
