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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==nullptr) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;

        //creating gap of n between fast and slow pointers
        int count=0;
        while(count<n){
            fast=fast->next;
            count++;
        }

        //if deleting node is head 
        if(fast==nullptr){
            return head->next;
        }

        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        //slow pointing to the node previous to deleting node
        ListNode* deleteNode=slow->next;
        slow->next=deleteNode->next;
        deleteNode->next=nullptr;

        return head;


    }
};
