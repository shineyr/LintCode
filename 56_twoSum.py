'''
56 两数之和

给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。

你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。

 注意事项

你可以假设只有一组答案。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].

'''

class Solution:
    """
    @param numbers : An array of Integer
    @param target : target = numbers[index1] + numbers[index2]
    @return : [index1 + 1, index2 + 1] (index1 < index2)
    """

    def twoSum(self, numbers, target):
        # write your code here
        ret = []
        for i in range(len(numbers)):
            for j in range(i + 1, len(numbers)):
                if numbers[i] + numbers[j] == target:
                    ret.append(i+1)
                    ret.append(j+1)

        return ret


s = Solution()
l = [2,7,11,15]

print(s.twoSum(l,9))