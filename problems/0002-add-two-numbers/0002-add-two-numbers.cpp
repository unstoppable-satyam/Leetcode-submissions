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
private: 
    void print(ListNode* l1){
        cout<<" printing ll "<<endl;
        while(l1 != NULL){
            cout<<l1->val<<" ";
            l1 = l1->next;
        }
        cout<<endl;
    }

public:
    ListNode* addTwoNumbers(ListNode* ll1, ListNode* ll2) {
        int carry = 0, sum = 0;
        ListNode* cur1 = ll1;
        ListNode* cur2 = ll2;

        
        sum = cur1->val + cur2->val;
        carry = sum/10;
        ListNode* ret = new ListNode( sum%10);
        ListNode* ret_cur = ret;
        cur1 = cur1->next;
        cur2 =cur2->next;
        while( cur1 != NULL || cur2 != NULL){
            sum = carry;
            if(cur1)  sum += cur1->val; 
            if(cur2)  sum += cur2->val;
            carry = sum/10;

            ret_cur->next = new ListNode(sum%10);
            ret_cur = ret_cur->next;
            if(cur1) cur1 = cur1->next;
            if(cur2) cur2 =cur2->next;
        }
        if( carry ){
            ret_cur->next =  new ListNode(carry);
        }
        return ret;
    }
};