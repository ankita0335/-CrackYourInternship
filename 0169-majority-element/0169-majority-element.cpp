class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int c=nums.size()/2;
        for(auto i:mp)
        {
            if(i.second>c)
            {
                return i.first;
            }
        }
        return {};
    }
};