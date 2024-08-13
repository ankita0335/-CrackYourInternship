class Solution {
    void solve(int ind,int target,vector<int>&nums,vector<vector<int>>&ans,vector<int>&v){
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target)break;
            v.push_back(nums[i]);
            solve(i+1,target-nums[i],nums,ans,v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,ans,v);
        return ans;
    }
};