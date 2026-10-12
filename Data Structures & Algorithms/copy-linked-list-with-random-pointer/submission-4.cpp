/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* helper(Node* head,unordered_map<Node*,Node*>& mp){
        if(!head) return nullptr;

        if(!mp.count(head)){
            mp[head]=new Node(head->val);
        }

        return mp[head];
    }

    Node* copyRandomList(Node* head) {
        // HashMap with one pass
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while (temp) {
            if (!mp.count(temp)) {
                mp[temp] = new Node(temp->val);
            }

            mp[temp]->next=helper(temp->next,mp);
            mp[temp]->random=helper(temp->random,mp);

            temp = temp->next;
        }

        return mp[head];
    }
};
