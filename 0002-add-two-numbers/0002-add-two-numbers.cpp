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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp=new ListNode(0);
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        int carry=0;
        ListNode* head=tmp;
        while( ptr1 && ptr2)
        {
            int sum=ptr1->val+ptr2->val+carry;
            carry=sum/10;
            tmp->next=new ListNode(sum%10);
            tmp=tmp->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        while(ptr1)
        {
            int sum=ptr1->val+carry;
            carry=sum/10;
            tmp->next=new ListNode(sum%10);
            tmp=tmp->next;
            ptr1=ptr1->next;
        }

        while(ptr2)
        {
            int sum=ptr2->val+carry;
            carry=sum/10;
            tmp->next=new ListNode(sum%10);
            tmp=tmp->next;
            ptr2=ptr2->next;
        }
        //Input: //l1 =[9,9,9,9,9,9,9] l2 =[9,9,9,9]
        //Output [8,9,9,9,0,0,0,1]
        if(carry)        
        {
            tmp->next=new ListNode(carry);
        }
        
        return head->next;
    }
};