class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int j=n-1;
        int leftsum=0,rsum=0,maxi=0;
        for(int i=0;i<k;i++)
        {
            leftsum=leftsum+cardPoints[i];
            maxi=leftsum;
        }
        for(int i=k-1;i>=0;i--)
        {
            leftsum=leftsum-cardPoints[i];
            rsum=rsum+cardPoints[j];
            j--;
            maxi=max(leftsum+rsum,maxi);
        }
    return maxi;
    }
};