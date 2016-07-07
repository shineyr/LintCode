/*
212 空格替换

设计一种方法，将一个字符串中的所有空格替换成 %20 。你可以假设该字符串有足够的空间来加入新的字符，且你得到的是“真实的”字符长度。

你的程序还需要返回被替换后的字符串的长度。

 注意事项

如果使用 Java 或 Python, 程序中请用字符数组表示字符串。

样例
对于字符串"Mr John Smith", 长度为 13

替换空格之后，参数中的字符串需要变为"Mr%20John%20Smith"，并且把新长度 17 作为结果返回。
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if(string == NULL || length <= 0)
        {
            return 0;
        }//if
        
        int len = 0, blankNum = 0;
        while(string[len] != '\0')
        {
            if(string[len] == ' ')
            {
                ++blankNum;
            }
            ++len;
        }//while
        
        int newLen = len + 2 * blankNum;
       
        for(int i=newLen-1,j=len-1; i>=0 && j>=0;--j)
        {
            if(string[j] == ' ')
            {
                string[i--] = '0';
                string[i--] = '2';
                string[i--] = '%';
            }//if
            else{
                string[i--] = string[j];
            }//else
        }//for
        
        return newLen;
    }
};  