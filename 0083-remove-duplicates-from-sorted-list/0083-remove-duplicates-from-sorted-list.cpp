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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) 
            return nullptr;
        ListNode* prev = head;
        ListNode* ptr = prev->next;
        while(ptr!=nullptr) 
        {
            if (prev->val==ptr->val) 
            {
                prev->next=ptr->next;
                delete ptr; // Free the memory of the duplicate node
            } 
            else 
            {
                prev=prev->next;
            }
            ptr=prev->next;
        }
        
        return head;
    }
};
