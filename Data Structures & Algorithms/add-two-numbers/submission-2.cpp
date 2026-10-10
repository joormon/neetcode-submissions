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
         ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while (l1 || l2) {
            int sum = 0;
            if (l1)
                sum += l1->val;
            if (l2)
                sum += l2->val;
            if (carry)
                sum += carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            temp = temp->next;
        }

        if (carry) {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
