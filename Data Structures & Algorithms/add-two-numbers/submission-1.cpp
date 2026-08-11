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

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int totalVal = 0;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 != NULL && l2 != NULL) {
            totalVal = l1->val + l2->val + carry;
            ListNode* tempNode = new ListNode(totalVal % 10);
            curr->next = tempNode;
            curr = tempNode;

            if ((totalVal / 10) > 0) {
                if (l1->next == NULL && l2->next == NULL) {
                    ListNode* tempNode1 = new ListNode(totalVal / 10);
                    curr->next = tempNode1;
                    curr = tempNode1;
                } else {
                    carry = totalVal / 10;
                }
            } else {
                carry = 0;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int totalval = carry + l1->val;
            ListNode* tempNode3 = new ListNode((totalval) % 10);
            curr->next = tempNode3;
            curr = tempNode3;
            if (totalval / 10 > 0) {
                if (l1->next == NULL) {
                    curr->next = new ListNode(totalval / 10);
                    curr = curr->next;
                } else {
                    carry = totalval / 10;
                }
            } else {
                carry = 0;
            }

            l1 = l1->next;
        }

        while (l2) {
            int totalval = carry + l2->val;
            ListNode* tempNode3 = new ListNode((totalval) % 10);
            curr->next = tempNode3;
            curr = tempNode3;
            if (totalval / 10 > 0) {
                if (l2->next == NULL) {
                    curr->next = new ListNode(totalval / 10);
                    curr = curr->next;
                } else {
                    carry = totalval / 10;
                }
            } else
                carry = 0;
            l2 = l2->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
