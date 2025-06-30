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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return 0;

        int n = 0; ListNode* curr = head; ListNode* tail = head;
        while(curr != nullptr) {
            n++;
            if(curr -> next == nullptr) tail = curr;
            curr = curr -> next;
        }
        k = k % n;

        curr = head;
        tail -> next = curr;
        for(int i = 1; i < n-k; i++) {
            curr = curr->next;
        }
        head = curr -> next;
        curr -> next = nullptr;

        return head;
    }
};