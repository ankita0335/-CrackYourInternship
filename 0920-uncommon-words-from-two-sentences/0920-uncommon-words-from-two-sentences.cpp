class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        string word = "";
        for (int i = 0; i <= s1.size(); i++) 
        {
            if (i == s1.size() || s1[i] == ' ') 
            {
                if (!word.empty()) 
                {
                    mp[word]++;
                    word = "";
                }
            } 
            else 
            {
                word += s1[i];
            }
        }
        for (int i = 0; i <= s2.size(); i++) 
        {
            if (i == s2.size() || s2[i] == ' ') 
            {
                if (!word.empty()) 
                {
                    mp[word]++;
                    word = "";
                }
            } 
            else 
            {
                word += s2[i];
            }
        }
        for (auto &i : mp) 
        {
            if (i.second == 1) 
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
