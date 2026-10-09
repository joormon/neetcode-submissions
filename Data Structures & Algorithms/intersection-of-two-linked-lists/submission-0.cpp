/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
         unordered_set<ListNode*> st;
        for(ListNode* curr=headA;curr!=nullptr;curr=curr->next){
            st.insert(curr);
        }

        for(ListNode* curr=headB;curr!=nullptr;curr=curr->next){
            if(st.count(curr)){
                return curr;
            }
        }

        return nullptr;
    }
};