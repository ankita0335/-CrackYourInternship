class Solution {
public:
    void solve(vector<int>&nums,int i,set<vector<int>>&v,vector<int>&curr)
    {
        if(i==nums.size())
        {
            
            v.insert(curr);
            return ;
        }
        curr.push_back(nums[i]);
        solve(nums,i+1,v,curr);
        curr.pop_back();
        solve(nums,i+1,v,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>curr;
        solve(nums,0,st,curr);
        vector<vector<int>>v1(st.begin(),st.end());
        return v1;
    }
};