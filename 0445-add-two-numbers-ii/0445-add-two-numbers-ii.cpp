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
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* nextt=nullptr;
        while(curr!=nullptr)
        {
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1=reverse(l1);
        ListNode* ptr2=reverse(l2);
        int carry=0,sum=0;
        ListNode* res=new ListNode(0);
        ListNode* head=res;
        while(ptr1 && ptr2)
        {
            sum=ptr1->val+ptr2->val+carry;
            carry=sum/10;
            res->next=new ListNode(sum%10);
            res=res->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1)
        {
            sum=ptr1->val+carry;
            carry=sum/10;
            res->next=new ListNode(sum%10);
            res=res->next;
            ptr1=ptr1->next;            
        }
        while(ptr2)
        {
            sum=ptr2->val+carry;
            carry=sum/10;
            res->next=new ListNode(sum%10);
            res=res->next;
            ptr2=ptr2->next;            
        }
        if(carry)
        {
            res->next=new ListNode(carry);
        }
        ListNode* final = reverse(head->next);
        return final;
    }
};