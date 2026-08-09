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

    int countNode(ListNode* head)
    {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL)
        {
             count++;
            temp=temp->next; 
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int sizeList=countNode(head);
        int m=sizeList-n+1;//findin the node from the head;

        //Base cases for last and first node
        if(m==1)
        {
            ListNode * newHead=head->next;
            delete head;
            return newHead;
        }

        ListNode* curr=head;

        for(int i=1;i<m-1;i++)
        {
            curr=curr->next;//curr is at the previous node of the nth node
        }

        //curr is pointing at the node which comes before the nth node;
        ListNode * deleteNode=curr->next;
        curr->next=curr->next->next;
        delete deleteNode;
        return head;
    }
};
