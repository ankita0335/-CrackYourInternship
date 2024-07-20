class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();
        int maximumfromlast=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maximumfromlast=max(maximumfromlast,prices[i]);
            maxi=max(maxi,maximumfromlast-prices[i]);
        }
        return maxi;
    }
};