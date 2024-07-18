class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0;// Dutch flag algo 
        int n=nums.size();
        int r=n-1;
        while(j<=r)
        {
            if(nums[j]==0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==1)
            {
                j++;
            }
            else
            {
                swap(nums[j],nums[r]);
                r--;
            }
        }
    }
};