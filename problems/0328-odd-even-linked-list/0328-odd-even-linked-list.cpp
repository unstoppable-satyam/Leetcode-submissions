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
    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL || head->next == NULL ) return head;
        ListNode* odd = head;
        ListNode* even=  head->next;
        ListNode* toAdd = head->next;
        while(odd->next != NULL && even->next != NULL ){
            ListNode* nextOdd = even->next;
            even->next = nextOdd->next;
            odd->next = nextOdd;
            even = even->next;
            odd = odd->next;
        }
        odd->next = toAdd;
        return head;
    }
};




// if(!head || head->next == NULL ) return head;
//         ListNode* odd = head;
//         ListNode* even = head->next;
//         ListNode* even_node = head->next;
//         while( even != NULL && even->next != NULL){
//             odd->next = odd->next->next;
//             even->next = even->next->next;

//             odd = odd->next;
//             even = even->next;
//         }
//         odd->next = even_node;