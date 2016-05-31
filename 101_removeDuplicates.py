class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates(self, A):
        # write your code here
        if len(A) == 0:
            return 0
            
        times = 1
        k = 0
        for i in range(1,len(A)):
            if A[i] != A[k]:
                k += 1
                A[k] = A[i]
                times = 1
            else:
                if times >= 2:
                    continue
                else:
                    k += 1
                    A[k] = A[i]
                    times += 1
        
        del A[k+1:len(A)]
        
        return len(A)
          