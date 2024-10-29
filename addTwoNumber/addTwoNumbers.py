# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import Optional
from copy import deepcopy
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if l1 == None:
            return l2
        elif l2 == None:
            return l1
        
        tmp = ListNode()
        start = ListNode()
        start = tmp
        car = 0
        while(l1 != None or l2 != None):
            val = 0
            if(l1 == None):
                tmp_l1 = ListNode()
                l1 = tmp_l1
            elif (l2 == None):
                tmp_l2 = ListNode()
                l2 = tmp_l2
            val = l1.val + l2.val + car
            car = 0
            if val >= 10:
                val -= 10
                car = 1
            ln = ListNode(val)
            tmp.next = ln
            tmp = ln
            l1 = l1.next
            l2 = l2.next
        if car == 1:
            ln = ListNode(car)
            tmp.next = ln
        return start.next
        