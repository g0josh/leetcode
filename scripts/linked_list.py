from typing import List, Union

class ListNode(object):
    def __init__(self, value:int):
        self.value:int = value
        self.next:Union[ListNode, None] = None

def createNode(values:List[Union[int, str]]) -> ListNode:
    if len(values) < 1:
        return None

    head = ListNode(values[0])
    curr = head
    for i in range(1, len(values)):
        curr.next = ListNode(values[i])
        curr = curr.next
    return head    

def deleteNode(linkedListHead:ListNode, value:int):
    if linkedListHead.val == value:
        return linkedListHead.next
    curr = linkedListHead
    while curr.next is not None:
        if curr.next.val == value:
            if curr.next.next is None:
                curr.next = None
                return linkedListHead
            else:
                curr.next = curr.next.next
                return linkedListHead
        curr = curr.next
    return linkedListHead

def reverseList(linkedListHead:ListNode):
    if linkedListHead.next is None:
        return linkedListHead
    new = reverseList(linkedListHead.next)
    linkedListHead.next.next = linkedListHead
    linkedListHead.next = None
    return new


def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
    if l1 is None:
        return l2
    if l2 is None:
        return l1
    head:ListNode = l1 if l1.value < l2.value else l2
    merged = head
    curr1 = l1.next if head == l1 else l1
    curr2 = l2.next if head == l2 else l2
    def mergeCurr1():
        nonlocal curr1, merged
        merged.next = curr1
        curr1 = curr1.next
        merged = merged.next
    def mergeCurr2():
        nonlocal curr2, merged
        merged.next = curr2
        curr2 = curr2.next
        merged = merged.next

    while curr1 is not None or curr2 is not None:
        if curr2 is None:
            mergeCurr1()
        elif curr1 is None:
            mergeCurr2()
        elif curr1.value < curr2.value:
            mergeCurr1()
        else:
            mergeCurr2()
    return head

def isPalindrome(head: ListNode) -> bool:
    result = 0
    curr = head
    while curr is not None:
        result ^= ord(str(curr.value))
        curr = curr.next
    if result == 0 or (result > 47 and result < 58):
        return True
    else:
        return False

def hasCycle(head: ListNode) -> bool:
    map = {}
    index = 0
    curr = head
    while curr is not None:
        _id = id(curr)
        if _id in map:
            return map[_id]
        else:
            map[_id] = index
        index += 1
        curr = curr.next
    return -1

if __name__ == "__main__":
    ll = createNode([1, 2])
    # ll2 = createNode([2])
    # rll = reverseList(ll)
    # mll = mergeTwoLists(ll, ll2)
    # print("Is palindrome = {}".format(isPalindrome(ll)))
    print("List has a cycle = {}".format(hasCycle(ll)))