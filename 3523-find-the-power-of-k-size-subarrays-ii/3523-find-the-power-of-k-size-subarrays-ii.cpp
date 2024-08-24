class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>arr(nums.size(), 1);
        int n= nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]+1==nums[i])
            {
                arr[i]=arr[i-1]+1;
            }
        }
        vector<int>ans;
        for(int i= k-1; i< n ; i++)
        {
            if(arr[i]>=k)
            {
                ans.push_back(nums[i]);
            }
            else
                ans.push_back(-1);
        }
        return ans;
    }
};