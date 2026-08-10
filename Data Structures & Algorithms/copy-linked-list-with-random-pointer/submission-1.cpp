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
    Node* copyRandomList(Node* head) 
    {
        if(!head) return nullptr;

        //Interleave cloned nodes
        Node* curr=head;
        while(curr)
        {
            Node* copy=new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }

        //assigning random pointers to the cloned nodes
        curr=head;
        while(curr)
        {
            if(curr->random)
            {
                curr->next->random=curr->random->next;
            }
            
            curr=curr->next->next;
        }

        //detaching the cloned node and original nodes
        curr=head;
        Node* dummy = new Node(0);
        Node* copyCurr=dummy;

        while(curr)
        {
            Node* copyNode=curr->next;
            Node* originalNext=copyNode->next;

            copyCurr->next=copyNode;
            curr->next=originalNext;

            copyCurr=copyCurr->next;
            curr=originalNext;
        }

        Node* newHead=dummy->next;
        delete dummy;
        return newHead;
        

        // if(!head) return nullptr;
        // unordered_map<Node* ,Node*> mp;

        // Node* curr=head;
        // while(curr)
        // {
        //     mp[curr]=new Node(curr->val);
        //     curr=curr->next;
        // }    

        // curr=head;
        // while(curr)
        // {
        //     mp[curr]->next=mp[curr->next];
        //     mp[curr]->random=mp[curr->random];
        //     curr=curr->next;
        // }

        // return mp[head];
    }
};
