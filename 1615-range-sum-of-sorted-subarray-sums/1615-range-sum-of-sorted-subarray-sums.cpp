class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        int MOD = 1e9+7;
        for (int i = 0; i < n; ++i) 
        {
            int p = 0;
            for (int j = i; j < n; ++j) 
            {
                p += nums[j];
                arr.push_back(p);
            }
        }
        sort(arr.begin(), arr.end());
        int res = 0;
        for (int i = left - 1; i < right; ++i) 
        {
            res = (res + arr[i]) % MOD;
        }
        return res;
    }
};