//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool all0in(vector<int>&cnt)
    {
        for(auto ele: cnt)
        {
            if(ele!=0)
            {
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt) 
    {
        // code here
        int n=txt.size();
        vector<int>cnt(26,0);
        for(int i=0;i<pat.length();i++)
        {
            char ch = pat[i];
            cnt[ch-'a']++;
        }
        int i=0, j=0;
        int res=0;
        while(j<n)
        {
            cnt[txt[j]-'a']--;
            if(j-i+1 == pat.length())
            {
                if(all0in(cnt))
                {
                    res++;
                }
                cnt[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends