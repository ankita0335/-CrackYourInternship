class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        for(int j=1; j<n-1; ++j) {
            int lefti = 0;
            int leftd = 0;
            for(int i=0; i<j; ++i) {
                lefti += (rating[i] < rating[j]);
                leftd += (rating[i] > rating[j]);
            }
            int righti = 0;
            int rightd = 0;
            for(int k=j+1; k<n; ++k) {
                righti += (rating[j] < rating[k]);
                rightd += (rating[j] > rating[k]);
            }
            res += lefti * righti + leftd * rightd;
        }
        return res;
    }
};