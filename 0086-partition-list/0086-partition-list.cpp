
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* ptr= head;
        ListNode* large = new ListNode(0);
        ListNode* ptr1= small;
        ListNode* ptr2= large;
        while(ptr != nullptr)
        {
            if(ptr->val < x)
            {
                ptr1->next= ptr;
                ptr1=ptr1->next;
            }
            else 
            {
                ptr2->next = ptr;
                ptr2=ptr2->next;
            }
            ptr = ptr->next;
        }
        ptr2->next= nullptr;
        ptr1->next=large->next;
        return small->next;
    }
};