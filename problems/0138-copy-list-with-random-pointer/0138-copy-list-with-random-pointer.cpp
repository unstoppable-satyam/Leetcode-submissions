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
        if( !head ) return NULL;
        Node* node = head;
        while(node){
            Node* temp = new Node(node->val);
            Node* next_node = node->next;
            node->next = temp;
            temp->next = next_node;
            node = next_node;
        }


        Node* clone_head = head->next;
        Node* cur = clone_head;
        node = head;
        while(node){
            Node* rd = node->random;
            if(rd)cur->random = rd->next;
            else cur->random = nullptr;

            node = cur->next;
            if(node)cur = node->next;
        }

        node = head;
        cur = clone_head;
        while(node){
            node->next = cur->next;
            node = cur->next;
            if(node)cur->next = node->next;
            if(node)cur = node->next;
        }
        return clone_head;

        // map< Node* , Node* > mp; // old node to new node map

        // Node * clone = new Node(head->val);
        // mp[head] = clone;

        // Node* temp = head->next;
        // Node* prev = clone;

        // while( temp != NULL ){
        //     Node* newNode = new Node(temp->val);
        //     prev->next = newNode;

        //     mp[temp] = newNode;
        //     temp = temp->next;
        //     prev = prev->next;
        // }

        // temp = head;
        // Node* cur = clone;
        // while(temp != NULL){
        //     Node* rd = temp->random;
        //     Node* new_rd = mp[rd];
        //     cur->random = new_rd;

        //     temp = temp->next;
        //     cur = cur->next;
        // }
        // return clone;
    }
};