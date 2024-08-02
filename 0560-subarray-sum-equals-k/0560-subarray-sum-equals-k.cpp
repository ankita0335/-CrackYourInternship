class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1; // Initialize with a sum of 0
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            // Check if there is a subarray with sum k ending at the current index
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }
            sumFreq[sum]++;
        }
        return count;
    }
};