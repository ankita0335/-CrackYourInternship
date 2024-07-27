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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        stack<int>st;
        int re=0;
        int n=v.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=v[i])
            {
                st.pop();
            }
            if(!st.empty())
                re=st.top();
            else
                re=0;
            st.push(v[i]);
            res.push_back(re);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};