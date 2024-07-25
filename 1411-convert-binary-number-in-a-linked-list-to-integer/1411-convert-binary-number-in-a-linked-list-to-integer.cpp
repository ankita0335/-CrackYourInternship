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
    ListNode* reverse(ListNode* head)
    {
        ListNode* ptr=head;
        ListNode* pre=nullptr;
        ListNode* nxtt=nullptr;
        while(ptr!=nullptr)
        {
            nxtt=ptr->next;
            ptr->next=pre;
            pre=ptr;
            ptr=nxtt;
        }
        head=pre;
        return head;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* rev=reverse(head);
        int i=0;
        int ans=0;
        while(rev!=nullptr)
        {
            int curr=rev->val;
            ans+=pow(2,i)*curr;
            i++;
            rev=rev->next;
        }
        return ans;
    }
};