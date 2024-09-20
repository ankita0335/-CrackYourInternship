class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i: s)
        {
            mp[i]++;
        }
        vector<pair<int,char>>v;
        for(auto i: mp)
        {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string  ans;
        for(auto i: v)
        {
            for(int j=0;j<i.first;j++)
            {
                ans+= i.second;
            }
        }
        return ans;
    }
};