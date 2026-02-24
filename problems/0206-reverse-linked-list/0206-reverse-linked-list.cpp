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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL ) return head;
        ListNode* last = NULL;
        ListNode* cur = head;
        ListNode* future = head->next;
        while(cur != NULL ){
            cur->next = last;
            last = cur;
            cur = future;
            if( future != NULL ) future = future->next;
        }
        return last;
    }

};