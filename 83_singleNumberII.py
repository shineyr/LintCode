"""
83 落单的数 II

给出3*n + 1 个的数字，除其中一个数字之外其他每个数字均出现三次，找到这个数字。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 [1,1,2,3,3,3,2,2,4,1] ，返回 4
"""
class Solution:
    """
	@param A : An integer array
	@return : An integer
    """
    #方法一：哈希的思想，求每个关键字出现的次数
    def singleNumberII(self, A):
        # write your code here
        dict = {}
        for i in A:
            if i in dict:
                dict[i] += 1
            else:
                dict[i] = 1

        for key in dict:
            if dict[key] == 1:
                return key


A = [1,1,2,3,3,3,2,2,4,1]
s = Solution()

print(s.singleNumberII(A))