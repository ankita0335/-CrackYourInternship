class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=1;
        while(j<nums.size())
        {
            if(nums[i]==0 && nums[j]!=0)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            if(nums[i]!=0)  i++; //[1,0,1] isme nums[j]=0 hai but agr ye condition nhi lgau to glt ans ayega
            j++;
        }
    }
};