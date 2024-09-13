class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int>ans;
        int i = 0 , n= queries.size();
        while(i<n)
        {
            int xorr = arr[queries[i][0]];
            for(int l = queries[i][0]+1; l <=queries[i][1]; l++)
            {
                xorr ^= arr[l];
            }
            ans.push_back(xorr);
            i++;
        }
        return ans;
    }
};