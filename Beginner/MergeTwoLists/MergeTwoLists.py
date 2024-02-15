from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        
        
        current = dummy = ListNode(0)
        while list1 and list2:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        
        if list1:
            current.next = list1
        if list2:
            current.next = list2
        return dummy.next
    

list1 = [1,2,4]
list2 = [1,3,4]

list11 = []
list22 = []

list111 = []
list222 = [0]

s = Solution()
print(f"The new sorted list is: {s.mergeTwoLists(list1,list2)}");
print(f"The new sorted list is: {s.mergeTwoLists(list11,list22)}");
print(f"The new sorted list is: {s.mergeTwoLists(list111,list222)}");