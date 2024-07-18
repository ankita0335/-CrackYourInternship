class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v=nums;
        int n=nums.size();
        sort(v.begin(),v.end());
        int l=0,r=v.size()-1;
        int sum=0;
        while(l<r)
        {
            sum=v[l]+v[r];
            if(sum==target)
            {
                break;
            }
            else if(sum<target)
            {
                l++;
            }
            else
                r--;
        }
        vector<int>ans;  //If I initialize ans with a size of 2 and then use push_back, 
                        //the final vector will have more than two elements, which is not what we want.
        for(int i=0;i<n;i++)
        {
            if(nums[i]==v[l] || nums[i]==v[r])
                ans.push_back(i);
        }
        return ans;
    }
};