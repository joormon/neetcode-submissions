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
    Node* lowestCommonAncestor(Node* p, Node * q) {
       Node* p_t=p;
       Node* q_t=q;

       while(p_t!=q_t){
           !p_t?p_t=q:p_t=p_t->parent;
           !q_t?q_t=p:q_t=q_t->parent;
       }

       return p_t;
    }
};