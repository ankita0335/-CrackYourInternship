class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0, maxLength = 0;
        unordered_map<char, int> countMap;
        int start = 0;
        for (int end = 0; end < s.size(); ++end) 
        {
            countMap[s[end]]++;
            maxCount = max(maxCount, countMap[s[end]]);    
            if (end - start + 1 - maxCount > k) 
            {
                countMap[s[start]]--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};