class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        priority_queue<pair<int, int >, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i], i });
        }
        long long score=0;
        int n=nums.size();
        while(!pq.empty())
        {
            auto curr= pq.top().second;
            if(nums[curr]>0)
            {
                score+=pq.top().first;
                if(curr-1>=0)
                {
                    nums[curr-1]=0;
                }
                if(curr+1<n)
                {
                    nums[curr+1]=0;
                }
            }
            pq.pop();
        }
        return score;
    }
};