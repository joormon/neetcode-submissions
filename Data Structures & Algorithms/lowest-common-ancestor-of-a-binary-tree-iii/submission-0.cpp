/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    //solved using a hash set;
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> st;
        while(p){
            st.insert(p);
            p=p->parent;
        }

        while(q){
            if(st.count(q)) return q;
            q=q->parent;
        }

        return nullptr;
    }
};