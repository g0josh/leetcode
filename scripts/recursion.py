#!/usr/bin/env python

def reverseString(l):
    def reverse(first, last):
        print("Got ", first, last)
        if last - first > 0:
            s = l[first]
            l[first] = l[last]
            l[last] = s
            reverse(first+1 , last-1)
    reverse(0, len(l)-1)

class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None

def createLinkedList(values):
    head = ListNode(values[0])
    def _create(node,index):
        newNode = ListNode(values[index])
        node.next = newNode
        if index + 1 < len(values):
            _create(newNode, index+1)
    _create(head,1)
    return head

def printLinkedList(ll):
    _ll = ll
    while True:
        print(_ll.value)
        if _ll.next is None:
            break
        _ll = _ll.next

# def swapLinkedList(ll):
#     # _ll = ll
#     # head = ll.next
#     def _swap(node):
#         if node is not None and node.next is not None:
#             s = node
#             e = node.next
#             s.next = e.next
#             node = e
#             node.next = s
#             _swap(node.next.next)
#     _swap(ll)
#     # return _ll


def swapLinkedList(node):
    def _swap(ll):
        s = ll
        ll = ll.next
        ll.next = s
        # if ll.next.next is None:
        #     return ll
        ll.next.next = _swap(ll.next.next)
    _swap(node)
    return node



if __name__ == "__main__":
    # Reverse String in place
    # l = ['h','e','l','l','o']
    # reverseString(l)
    # print(l)

    # Swap linked list
    ll = createLinkedList([1,2,3,4,5,6])
    print("Original")
    printLinkedList(ll)
    lls = swapLinkedList(ll)
    print("Swapped")
    printLinkedList(lls)




