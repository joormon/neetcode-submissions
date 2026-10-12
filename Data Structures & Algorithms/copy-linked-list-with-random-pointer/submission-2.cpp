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
    // Hash Map using two passes
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        // create the copied nodes
        Node* tail = head;
        while (tail) {
            mp[tail] = new Node(tail->val);
            tail = tail->next;
        }

        tail = head;
        while (tail) {
            mp[tail]->next = mp[tail->next];
            mp[tail]->random = mp[tail->random];
            tail = tail->next;
        }

        return mp[head];
    }
};
