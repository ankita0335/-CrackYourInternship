class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int curr=0;
        int c=0;
        int n= rocks.size();
        int m= capacity.size();
        for(int i=0;i<m;i++)
        {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for(int i=0;i<n;i++)
        {
            if(additionalRocks>=capacity[i])
            {
                c++;
                additionalRocks-=capacity[i];
            }
            if(additionalRocks==0)
                break;
        }
        return c;
    }
};