from typing import List, Union

class Node(object):
    def __init__(self, value:int):
        self.value:int = value
        self.next:Union[Node, None] = None

def createNode(values:List[Union[int, str]]) -> Node:
    if len(values) < 1:
        return None

    head = Node(values[0])
    curr = head
    for i in range(1, len(values)):
        curr.next = Node(values[i])
        curr = curr.next
    return head    


if __name__ == "__main__":
    ll = createNode([1])