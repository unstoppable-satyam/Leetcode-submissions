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
   ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* cur = lists[i];
            while(cur != NULL) {
                minh.push(cur->val);
                cur = cur->next;
            }
        }

        // Create a dummy node to simplify the process of appending nodes
        ListNode dummy;
        ListNode* tail = &dummy;

        // Extract elements from the min-heap and form the sorted linked list
        while(!minh.empty()) {
            tail->next = new ListNode(minh.top());
            minh.pop();
            tail = tail->next;
        }

        // Return the merged sorted linked list
        return dummy.next;
    }
};