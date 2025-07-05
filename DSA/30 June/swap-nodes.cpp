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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0; ListNode* curr = head;
        while(curr!=nullptr){
            n++;
            curr = curr->next;
        }

        int first = k, last = n-k+1;
        ListNode *firstP = nullptr;
        ListNode *lastP = nullptr;
        curr = head;
        int cp = 1;
        while(curr != nullptr){
            if(cp == first) firstP = curr;  
            if(cp == last) lastP = curr;
            curr = curr -> next;
            cp++;
        }
        swap(firstP->val, lastP->val);
        return head;
    }
};