class Solution {
public:
    bool isPal(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string &s,int indx,vector<string>&curr, vector<vector<string>>&ans)
    {
        int n=s.length();
        if(indx==n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=indx;i<n;i++)
        {
            if(isPal(s,indx,i))
            {
                curr.push_back(s.substr(indx,i-indx+1));
                solve(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<string>curr;
        vector<vector<string>>ans;
        solve(s,0,curr,ans);
        return ans;
    }
};