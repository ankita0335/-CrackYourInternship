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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>> res(m, vector<int>(n, -1)); 
        ListNode* ptr = head;
        int top =0, bottom = m-1, left=0, right=n-1;
        while (top <= bottom && left <= right) 
        {
            for (int j = left; j <= right && ptr != nullptr; j++) 
            {
                res[top][j] = ptr->val;
                ptr = ptr->next;
            }
            top++;
            for (int i = top; i <= bottom && ptr != nullptr; i++) 
            {
                res[i][right] = ptr->val;
                ptr = ptr->next;
            }
            right--;
            for (int j = right; j >= left && ptr != nullptr; j--) 
            {
                res[bottom][j] = ptr->val;
                ptr = ptr->next;
            }
            bottom--;
            for (int i = bottom; i >= top && ptr != nullptr; i--) 
            {
                res[i][left] = ptr->val;
                ptr = ptr->next;
            }
            left++;
        }
        return res;
    }
};
