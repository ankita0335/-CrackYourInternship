class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int>xorr(arr.size()+1,0);
        vector<int>ans;
        for(int i=1;i<=arr.size();i++)
        {
            xorr[i]=xorr[i-1] ^ arr[i-1];
        }
        for(int i=0 ;i< queries.size(); i++)
        {
            ans.push_back(xorr[queries[i][0]] ^ xorr[queries[i][1]+1]);
        }
        return ans;
    }
};