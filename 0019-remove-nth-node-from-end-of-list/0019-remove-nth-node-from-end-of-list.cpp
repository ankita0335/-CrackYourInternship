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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr= head;
        int c=0;
        while(ptr!=nullptr)
        {
            c++;
            ptr=ptr->next;
        }
        int newn=c-n;
        ptr=head;
        if(c==n)
            return head->next;
        int i=1;
        while(i<newn && ptr!=nullptr)
        {
            ptr=ptr->next;
            i++;
        }
        ptr->next=ptr->next->next;
        return head;
    }
};