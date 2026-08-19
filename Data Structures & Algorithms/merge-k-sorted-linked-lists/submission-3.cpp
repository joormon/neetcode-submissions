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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // Attach whatever is left in O(1) time
        curr->next = (l1 != nullptr) ? l1 : l2;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;

        int k = lists.size();

        while (k > 1) {
            int newK = 0;
            for (int i = 0; i < k; i += 2) {
                if (i + 1 < k)  // taking pair of lists
                {
                    lists[newK++] = merge2Lists(lists[i], lists[i + 1]);
                } else  // odd number list which is left out
                {
                    lists[newK++] = lists[i];
                }
            }
            k = newK;
        }

        return lists[0];
    }
};
