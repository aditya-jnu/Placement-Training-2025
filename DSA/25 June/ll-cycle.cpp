/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* curr = head;
        while(curr != nullptr){
            mpp[curr]++;
            if(mpp[curr] > 1) return true;
            curr = curr -> next;
        }
        return false;
    }
};