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


"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""


# 合并两个链表
def merge(head1, head2):
    if head1 is None:
        return head2
    if head2 is None:
        return head1
    p = head1
    q = head2

    head = None
    r = head

    while p is not None and q is not None:
        if p.val <= q.val:
            if head is None:
                head = p
                r = head
            else:
                r.next = p
                r = r.next

            p = p.next
            r.next = None
        else:
            if head is None:
                head = q
                r = head
            else:
                r.next = q
                r = r.next

            q = q.next
            r.next = None

    if p is not None:
        r.next = p
    if q is not None:
        r.next = q
    return head


class Solution:
    """
    @param lists: a list of ListNode
    @return: The head of one sorted list.
    """
    def mergeKLists(self, lists):
        # write your code here
        n = len(lists)
        if n <= 0:
            return None
        head = lists[0]
        for i in range(1, n):
            head = merge(head, lists[i])
        return head


head1 = None

for i in range(1,6):
    head1 = insert(head1,i+1)

head2 = None

for i in range(1,6):
    head2 = insert(head2,i+2)

display(head1)
display(head2)

l = [head1,head2]

head = Solution().mergeKLists(l)

display(head)