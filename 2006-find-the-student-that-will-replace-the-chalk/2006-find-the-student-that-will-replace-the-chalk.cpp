class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int n=chalk.size();
        long long sum=0;
        for(auto i: chalk)
        {
            sum+= i;
        }   
        int rem = k% sum;
        for(int i=0;i<n;i++)
        {
            if(rem<chalk[i])
            {
                return i;
            }
            rem -= chalk[i];
        }
        return -1;
    }
};