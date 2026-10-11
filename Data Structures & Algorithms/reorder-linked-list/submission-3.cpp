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
    void mergeList(ListNode* head1, ListNode* head2) 
    {
        while (head1 != NULL && head2 != NULL) {
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;
            head1->next = head2;
            if (temp1 == NULL) break;
            head2->next = temp1;

            head1 = temp1;
            head2 = temp2;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }


    void reorderList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow pointer is pointing at the half of the list

        ListNode* halfHead = reverse(slow->next);  // This Half head will act like tail

        // Setting the slow pointer next to null;
        slow->next = NULL;

        // Till now we have two separate lists
        // we will merge this list according to order

        mergeList(head, halfHead);
    }
};
