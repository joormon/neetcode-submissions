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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector<int> nodes;
        
        for(auto lst: lists)
        {
            while(lst!=NULL)
            {
                nodes.push_back(lst->val);
                lst=lst->next;
            }
        }

        sort(nodes.begin(),nodes.end());
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        for(int ele:nodes)
        {
            temp->next=new ListNode(ele);
            temp=temp->next;
        }

        ListNode* newHead=dummy->next;  
        delete dummy;
        return newHead;
    }
};
