class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n= nums.size();
        int h= n-1;
        while(l<=h)
        {
            int mid= l+(h-l)/2;
            if(nums[mid]== target)
            {
                return mid;
            }
            if(nums[mid]>= nums[l])
            {
                if(target >= nums[l] && target< nums[mid])
                {
                    h= mid-1;
                }
                else 
                    l=mid+1;
            }
            else 
            {
                if(target> nums[mid] && target<= nums[h])
                {
                    l= mid+1;
                }
                else
                    h= mid-1;
            }
        }
        return -1;
    }
};
              