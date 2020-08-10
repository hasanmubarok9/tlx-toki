class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def insert(self,head,data): 
    #Complete this method
        print("head ", head)
        print("data ", data)
        if head is None:
            return Node(data)
        elif head.next is None:
            head.next = Node(data)
        else:
            self.insert(head.next, data)

        return head

mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    print("head di for before insert", head)  
    head=mylist.insert(head,data)  
    print("head di for after insert", head)  
mylist.display(head)

# input sample
# 4
# 2
# 3
# 4
# 1