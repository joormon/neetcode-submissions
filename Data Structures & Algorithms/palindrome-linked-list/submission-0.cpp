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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
         ListNode* midNode=middle(head);
        ListNode* newHead=reverse(midNode);

        ListNode* temp1=head;
        ListNode* temp2=newHead;

        while(temp1!=nullptr && temp2!=nullptr ){
            if(temp1->val != temp2->val){
                //preserving the orginal list
                reverse(newHead);
                return false;
            }

            temp1=temp1->next;
            temp2=temp2->next;
        }

        //To preserve the orginal list 
        reverse(newHead);

        return true;
    }
};