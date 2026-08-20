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

    ListNode* getKthNode(ListNode* head,int k)
    {
        ListNode* curr=head;
        while(curr!=NULL && k>0)
        {
            curr=curr->next;
            k--;
        }

        return curr;
    }

public:

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prevGroupEnd=dummy;
        while(true)
        {
            
            ListNode* groupEnd=getKthNode(prevGroupEnd,k);
            if(!groupEnd) break;

            ListNode* nextGroupStart=groupEnd->next;
            
            ListNode* prev=nextGroupStart;
            ListNode* curr=prevGroupEnd->next;

            while(curr!=nextGroupStart)
            {
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }

            ListNode* groupStart=prevGroupEnd->next;
            prevGroupEnd->next=groupEnd;
            prevGroupEnd=groupStart;
        }

        return dummy->next;
    }
};
