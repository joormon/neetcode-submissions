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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
          ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        
        for(int count=0;count<left-1;count++){
            prev=prev->next;
        }

        ListNode* curr=prev->next;

        ListNode* right_end=prev;

        for(int count=0;count<right-left+1;count++){
            ListNode*temp=curr->next;
            curr->next=right_end;
            right_end=curr;
            curr=temp;
        }

        prev->next->next=curr;
        prev->next=right_end;

        ListNode* newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};