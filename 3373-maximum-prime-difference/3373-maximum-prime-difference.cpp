class Solution {
public:
    bool checkp(int num)
    {
        if(num<=1)  return false;
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        int dis=0;
        while(i<=j)
        {
            if(checkp(nums[i]) && checkp(nums[j]))
            {
                cout<<nums[i]<<nums[j];
                return j-i;
            }
            else if(!checkp(nums[j]))
            {
                j--;
            }
            else if(!checkp(nums[i]))
            {
                i++;
            }
        }
        return {};
    }
};