# Definition for singly-linked list with a random pointer.
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class RandomListNode:
    def __init__(self,x):
        self.label = x
        self.next = None
        self.random = None

def insert(head,val):
    node = RandomListNode(val)
    if head == None:
        return node

    p = head
    while p.next != None:
        p = p.next

    p.next = node
    return head

def display(head):
    p = head
    while p != None:
        print(p.label,end='\t')
        p = p.next
    print()


class Solution:
    # @param head: A RandomListNode
    # @return: A RandomListNode
    def copyRandomList(self, head):
        # write your code here
        if head is None:
            return None

        p = head
        while p is not None:
            r = p.next
            node = RandomListNode(p.label)
            node.next = p.next
            p.next = node
            p = r

        p = head
        q = p.next

        if q is None:
            print("None")
        while p is not None and q is not None:
            if p.random is not None:
                q.random = p.random.next
            p = q.next
            if p is not None:
                q = p.next

        ret = head.next
        del head
        q = ret
        while q.next is not None:
            p = q.next
            q.next = p.next
            del p
            q = q.next

        return ret


head = None

for i in range(1,6):
    head = insert(head,i)

display(head)

s = Solution()
ret = s.copyRandomList(head)

display(ret)