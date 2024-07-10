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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fwd = head;
        ListNode* bwd = head;
        while(n--){
            fwd = fwd->next;
        }
        //edge case -  n equals the size of LL and we have to delete the head
        if( fwd == NULL ){
            head = head->next;
            delete bwd;
            return head;
        }
        while(fwd->next != NULL ){
            bwd = bwd->next;
            fwd = fwd->next;           
        }
        // bwd is the preceding node of nth node from back
        ListNode* to_del = bwd->next;
        bwd->next = bwd->next->next;
        to_del->next = NULL;
        delete to_del;
        return head;
    }
};