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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre=&dummy;
        ListNode* curr=head;
        while(curr)
        {
            if(mp.find(curr->val)!=mp.end())
            {
                pre->next=curr->next;
                delete curr;
            }
            else
                pre=curr;
            curr=pre->next;
        }
        return dummy.next;
    }
};