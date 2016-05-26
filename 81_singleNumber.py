'''
81 落单的数

给出2*n + 1 个的数字，除其中一个数字之外其他每个数字均出现两次，找到这个数字。

样例
给出 [1,2,2,1,3,4,3]，返回 4

'''


class Solution:
    """
    @param A : an integer array
    @return : a integer
    """

    def singleNumber(self, A):
        # write your code here
        ret = 0
        for i in A:
            ret = ret ^ i
        return ret

A = [1,2,3,4,5,3,4,5,1]

s = Solution()
print(s.singleNumber(A))
