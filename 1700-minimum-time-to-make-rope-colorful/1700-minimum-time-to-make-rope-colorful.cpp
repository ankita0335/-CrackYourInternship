class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n= colors.size();
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            if(colors[i]== colors[i+1])
            {
                if(neededTime[i]<neededTime[i+1])
                {
                    c +=neededTime[i];
                }
                else
                {
                    c += neededTime[i+1];
                    neededTime[i + 1] = neededTime[i];
                }
            }
        }
        return c;
    }
};