class Solution {
public:
    unordered_map<string, vector<int>> mp;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        for(int i=0; i<n; i++){
            string f=strs[i];
            //strings are anagrams <=> same string after sorting
            sort(f.begin(), f.end());
            if (mp.count(f)==0) mp[f]={i};
            else mp[f].push_back(i);
        }
        vector<vector<string>> ans(mp.size());
        int i=0; 
        for(auto& [key, v] : mp){
            for(int x: v)
                ans[i].push_back(strs[x]); 
            i++;
        }  
        return move(ans);
    }
};