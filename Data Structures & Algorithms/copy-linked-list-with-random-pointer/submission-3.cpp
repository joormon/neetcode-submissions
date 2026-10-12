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
    Node* copyRandomList(Node* head) {
        // HashMap with one pass
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while (temp) {
            if (!mp.count(temp)) {
                mp[temp] = new Node(temp->val);
            }

            if (temp->next == nullptr) {
                mp[temp]->next = nullptr;
            } else if (mp.count(temp->next)) {
                mp[temp]->next = mp[temp->next];
            } else {
                mp[temp->next] = new Node(temp->next->val);
                mp[temp]->next = mp[temp->next];
            }

            if (temp->random == nullptr) {
                mp[temp]->random = nullptr;
            } else if (mp.count(temp->random)) {
                mp[temp]->random = mp[temp->random];
            } else {
                mp[temp->random] = new Node(temp->random->val);
                mp[temp]->random = mp[temp->random];
            }

            temp = temp->next;
        }

        return mp[head];
    }
};
