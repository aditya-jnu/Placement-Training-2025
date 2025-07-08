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
    int s = 0;
    ListNode* headNode;

    Solution(ListNode* head) {
        headNode = head;
        ListNode* temp = headNode;
        while(temp){
            s++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int ran_index = rand()%s;
        ListNode *temp = headNode;
        for(int i=1;i<=ran_index;i++){
            temp = temp -> next;
        }
        return temp -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */