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
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        ListNode* curr = head;
        while(curr != nullptr){
            temp.push_back(curr -> val);
            curr = curr->next;
        }

        int s = 0, e = temp.size()-1;
        while(s <= e){
            if(temp[s] == temp[e]){
                s++; e--;
            }
            else return false;
        }
        return true;
    }
};