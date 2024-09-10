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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr=head;
        while(ptr!=NULL && ptr->next!=NULL)
        {
            int m=gcd(ptr->val, ptr->next->val);
            ListNode *tmp= new ListNode();
            tmp->val=m;
            tmp->next=ptr->next;
            ptr->next=tmp;
            ptr=ptr->next->next;
        }
        return head;
    }
};