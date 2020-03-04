#!/usr/bin/env python

import math

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
    if len(values) == 0:
        return ListNode(None)
    head = ListNode(values[0])
    def _create(node,index):
        newNode = ListNode(values[index])
        node.next = newNode
        if index + 1 < len(values):
            _create(newNode, index+1)
    if len(values) > 1:
        _create(head,1)
    return head

def printLinkedList(ll):
    _ll = ll
    while True:
        print(_ll.value, end=" ")
        if _ll.next is None:
            print()
            break
        _ll = _ll.next

def getFibonacci(n):
    d = {}
    def fib(n):
        if n < 2:
            return n
        if n in d:
            return d[n]
        d[n] = getFibonacci(n-2) + getFibonacci(n-1)
        return d[n]
    return fib(n)

class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def power(x, y): 
    if (y == 0): 
        return 1
    temp = (power(x, int(y / 2)))
    if (int(y % 2) == 0):    
        return temp * temp
    else:
        if y < 0 : 
            return (temp*temp)/x
        else:
            return (x * temp * temp) 

def mergeTwoLists(l1, l2):
    if l1 is None and l2 is None:
        return l1
    if l1 is None and l2 is not None:
        return l2
    if l2 is None:
        return l1
    if l1.value < l2.value:
        l1.next = mergeTwoLists(l1.next, l2)
        return l1
    else:
        temp1 = l1
        temp2 = l2.next
        l1 = l2
        l1.next = temp1
        return mergeTwoLists(l1, temp2)

def kthGrammar(N, K):
    if N == 1:
        return 0
    else:
        value = kthGrammar(N-1, math.ceil(K/2))
        _result = [0,1] if value == 0 else [1,0]
        return _result[1] if (K%2) == 0 else _result[0]
    

if __name__ == "__main__":
    # Reverse String in place
    # l = ['h','e','l','l','o']
    # reverseString(l)
    # print(l)

    # fibonacci
    # print(getFibonacci(6))
    # print(power(2,-2))

    # Merge linked lists
    l1 = createLinkedList([])
    print("l1 = ", end = " ")
    printLinkedList(l1)
    l2 = createLinkedList([0])
    print("l2 = ", end = " ")
    printLinkedList(l2)
    l = mergeTwoLists(None,l2)
    print("Merged list = ", end = " ")
    printLinkedList(l)
    print("Kth grammar 4, 5 = ", kthGrammar(4,5))





