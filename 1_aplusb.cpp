/*
给出两个整数a和b, 求他们的和, 但不能使用 + 等数学运算符。
说明
a和b都是 32位 整数么？

是的
我可以使用位运算符么？

当然可以
样例
如果 a=1 并且 b=2，返回3
*/
class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        if (b == 0)
        {
               return a;
        }
        else {
            int c = a ^ b;
            int carry = (a & b) << 1;
            return aplusb(c,carry);
        }
    }
};