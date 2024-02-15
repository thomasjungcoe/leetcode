#include <cstddef>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next; 
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;

            ListNode* h, *cur1, *cur2;
            if(l1->val <= l2->val) {
                h = cur1 = l1;
                cur2 = l2;
            } else {
                h = cur1 = l2;
                cur2 = l1;
            }

            if (cur1->next == NULL) {
                cur1->next = cur2;
                return h;
            }

            // stop when one of the list ends
            while (cur2 != NULL && cur1 != NULL) {
                if (cur1->next == NULL) {
                    cur1->next = cur2;
                    cur1 = NULL;
                } else if (cur2->val <= cur1->next->val) {
                    // merge
                    ListNode* tmp = cur1->next;
                    cur1->next = cur2;
                    cur2 = cur2->next;
                    cur1->next->next = tmp;
                } else {
                    // move curl to the next
                    cur1 = cur1->next;
                }
            }
            return h;
        }

        // recursion
        ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;
            if (l1->val <= l2->val) {
                l1->next = mergeTwoLists2(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoLists2(l1, l2->next);
                return l2;
            }
        }

        // iterative
        ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {
            ListNode *head = new ListNode(-1);
            ListNode *cur = head;

            while(l1 != nullptr && l2 != nullptr) {
                if (l1->val <= l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }

            if (l1 != nullptr) {
                cur->next = l1;
            } else {
                cur->next = l2;
            }

            return head->next;
        }
};