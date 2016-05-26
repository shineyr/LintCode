"""
84 落单的数 III

 描述
 笔记
 数据
 评测
给出2*n + 2个的数字，除其中两个数字之外其他每个数字均出现两次，找到这两个数字。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 [1,2,2,3,4,4,5,3]，返回 1和5
"""


# 求第一个数值不同的位
def findFirstPos(A):
    pos = 0
    for a in A:
        pos = pos ^ a
    #寻找该异或结果中第一个不为0的位
    for i in range(32):
        if ((1 << i) & pos) != 0:
            return i


# 求一个列表的异或结果
def fun(A):
    pos = 0
    for a in A:
        pos = pos ^ a
    return pos


class Solution:
    """
    @param A : An integer array
    @return : Two integer
    """

    def singleNumberIII(self, A):
        list1 = []
        list2 = []
        pos = findFirstPos(A)
        #根据第pos位是不是1将原数组分为两个子数组
        for a in A:
            tmp = a >> pos
            if (tmp & 0x1) != 0:
                list1.append(a)
            else:
                list2.append(a)

        ret = []
        ret.append(fun(list1))
        ret.append(fun(list2))
        return ret

s = Solution()
A =  [1,2,2,3,4,4,5,3]

print(s.singleNumberIII(A))








