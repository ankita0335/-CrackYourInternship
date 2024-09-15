class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        unordered_map<string, int> mp;
        vector<int> vcnt(5, 0); 
        string crr = "00000"; 
        mp[crr] = -1;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) 
        {
            if (s[i] == 'a')      
                vcnt[0] = (vcnt[0] + 1) % 2;
            else if (s[i] == 'e') 
                vcnt[1] = (vcnt[1] + 1) % 2;
            else if (s[i] == 'i') 
                vcnt[2] = (vcnt[2] + 1) % 2;
            else if (s[i] == 'o') 
                vcnt[3] = (vcnt[3] + 1) % 2;
            else if (s[i] == 'u') 
                vcnt[4] = (vcnt[4] + 1) % 2;
            crr = "";
            for (int j = 0; j < 5; ++j) 
            {
                crr += to_string(vcnt[j]);
            }
            if (mp.find(crr) != mp.end()) 
                ans = max(ans, i - mp[crr]);
            else 
                mp[crr] = i;
        }
        return ans;
    }
};