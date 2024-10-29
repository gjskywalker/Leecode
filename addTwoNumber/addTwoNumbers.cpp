/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
 struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
    
        ListNode *tmp = new ListNode();
        ListNode *start = new ListNode();
        start = tmp;
        int car = 0;
        while(l1 != nullptr || l2 != nullptr) {
            int val = 0;
            if(l1 == nullptr) {
                ListNode* tmp_l1 = new ListNode(0);
                l1 = tmp_l1;
            }
            else if(l2 == nullptr) {
                ListNode* tmp_l2 = new ListNode(0);
                l2 = tmp_l2;
            }
            val = l1->val + l2->val + car;
            car = 0;
            if(val >= 10) {
                val -= 10;
                car = 1;
            }
            ListNode *ln = new ListNode(val);
            tmp->next = ln;
            tmp = ln;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (car == 1) {
            ListNode *ln = new ListNode(1);
            tmp->next = ln;
        }
        return start->next;
    }    
};

int main() {
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;

    ListNode* l4 = new ListNode(5);
    ListNode* l5 = new ListNode(6);
    ListNode* l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;

    Solution S;
    ListNode* start = new ListNode;
    start = S.addTwoNumbers(l1, l4);
    while(start != nullptr) {
        std::cout << start->val << std::endl;
        start = start->next;
    }
}