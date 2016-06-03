"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class ListNode(object):
    def __init__(self,val,next=None):
        self.val = val
        self.next = next

def insert(head,val):
    node = ListNode(val)
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
        print(p.val,end='\t')
        p = p.next
    print()

class Solution:
    """
    @param head: The first node of the linked list.
    @return: nothing
    """
    def reorderList(self, head):
        # write your code here
        if head is None or head.next is None:
            return

        p = head
        q = head.next
        while q is not None and q.next is not None:
            p = p.next
            q = q.next.next

        q = p.next
        p.next = None

        # 后半段节点逆序再逐个插入
        rHead = None
        while q is not None:
            r = q.next
            q.next = rHead
            rHead = q
            q = r

        q = rHead
        p = head
        while p is not None and q is not None:
            rr = q.next
            lr = p.next
            q.next = lr
            p.next = q
            q = rr
            p = lr
head = None

for i in range(1,6):
    head = insert(head,i)

display(head)

s = Solution()
s.reorderList(head)
display(head)
