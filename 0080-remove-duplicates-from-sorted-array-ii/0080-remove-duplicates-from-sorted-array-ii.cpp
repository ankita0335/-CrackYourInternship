class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        for(int e: nums)
        {
            if(i<2 || nums[i-2] != e)
            {
                nums[i]=e;
                i+=1;
            } 
        }
        return i;
    }
};