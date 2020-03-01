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

# def power(x, n):
#     def _power(x, n):
#         if n == 0:
#             return 1
#         # if n < 2:
#         #     return p*x
        
#         return _power(x*p, x, n-1)

#     if n < 0:
#         return 1 / _power(1, x, -1*n)
#     else:
#         return _power(1, x, n)

def power(x, y): 
    if (y == 0): 
        return 1
    temp = (power(x, int(y / 2)))
    if (int(y % 2) == 0):    
        return temp * temp
    else:
        if y < 0:
            
        else:    
            return (x * temp * temp) 

if __name__ == "__main__":
    # Reverse String in place
    # l = ['h','e','l','l','o']
    # reverseString(l)
    # print(l)

    # fibonacci
    print(getFibonacci(6))
    print(power(1.00001,0.5))





